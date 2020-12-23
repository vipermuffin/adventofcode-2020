//
//  Advent of Code 2020 Solutions: Day 20
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/20/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day20.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
//#include <functional> //std::function
//#include <iomanip> //setfill setw hex
#include <map>
#include <math.h> //sqrt
//#include <numeric> //std::accumulate
//#include <queue>
//#include <regex>
//#include <set>
//#include <sstream>
//#include <thread>
//#include <tuple>
#include <unordered_map>
#include <unordered_set>


using namespace std;
namespace AocDay20 {

    const uint8_t TOP = 0;
    const uint8_t LEFT = 3;
    const uint8_t RIGHT = 1;
    const uint8_t BOTTOM = 2;
    
    static const std::string InputFileName = "Day20.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto itv = tileFactory(input);
        auto result = findFourCorners(itv);
		return to_string(result);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto itv = tileFactory(input);
        auto x = findArrangement(itv);
		return to_string(x.countHash());
    }

    ImageTile::ImageTile(const std::vector<std::string>& image) {
        sides.reserve(8);
        string left(image.back().size(),'.');
        string right(image.back().size(),'.');
        sscanf(image.front().c_str(),"Tile %d:", &this->tileId);
        tileName = to_string(tileId);
        sides.push_back(image[1]);
//        sides.push_back(image[1]);
//        std::reverse(sides.back().begin(), sides.back().end());
        auto itr = image.begin()+1;
        int i = 0;
        while(itr != image.end()) {
            left[i] = itr->front();
            right[i] = itr->back();
            if(i!=0) {
                _image.emplace_back(itr->begin()+1,itr->end()-1);
            }
            i++;
            itr++;
        }
        _image.pop_back();
//        sides.push_back(left);
//        std::reverse(left.begin(),left.end());
        sides.push_back(right);
        
//        std::reverse(right.begin(),right.end());
//        sides.push_back(right);
        itr--;
        sides.push_back(*itr);
        sides.push_back(left);
//        sides.push_back(*itr);
//        std::reverse(sides.back().begin(), sides.back().end());
//        cout << "Tile ID: " << tileId << " created.\n";
//        printVector(sides);
    }
    
    ImageTile::ImageTile(const std::vector<std::string>& image, const int32_t idVal) {
        tileId = idVal;
        tileName = to_string(idVal);
        _image = std::vector<std::string>(image);
        
        sides.push_back(std::string(image.front().size()+2,'-'));
        sides.push_back(std::string(image.front().size()+2,'|'));
        sides.push_back(std::string(image.front().size()+2,'-'));
        sides.push_back(std::string(image.front().size()+2,'|'));
    }
    
    ImageTile::ImageTile(const ImageTile& copy) {
        tileId = copy.tileId;
        tileName = copy.tileName;
        sides = copy.sides;
        _image = copy._image;
    }
    
    bool ImageTile::isPossibleNeighbor(const ImageTile& it) const {
        bool neighbor = false;
        if((sides[TOP] == it.sides[BOTTOM]) ||
           (sides[RIGHT] == it.sides[LEFT]) ||
           (sides[LEFT] == it.sides[RIGHT]) ||
           (sides[BOTTOM] == it.sides[TOP])) {
            neighbor = true;
        }

        return neighbor;
    }
    
    uint8_t ImageTile::neighborLocation(const ImageTile& it) const {
        
        if(sides[TOP] == it.sides[BOTTOM])
            return TOP;
        if(sides[RIGHT] == it.sides[LEFT])
            return RIGHT;
        if(sides[LEFT] == it.sides[RIGHT])
            return LEFT;
        if(sides[BOTTOM] == it.sides[TOP])
            return BOTTOM;
        
        return 222;
    }
    
    void ImageTile::flip() {
        tileName.append("F");
        std::reverse(_image.begin(), _image.end());
        std::swap(sides[TOP],sides[BOTTOM]);
        std::reverse(sides[RIGHT].begin(), sides[RIGHT].end());
        std::reverse(sides[LEFT].begin(), sides[LEFT].end());
    }
    
    void ImageTile::rotateClockwise() {
        tileName.append("R");
        std::rotate(sides.rbegin(), sides.rbegin()+1, sides.rend());
        std::reverse(sides[TOP].begin(), sides[TOP].end());
        std::reverse(sides[BOTTOM].begin(), sides[BOTTOM].end());
        
        auto copy{_image};
        for(int i = 0; i < _image.size();i++) {
            auto sz = _image.size()-1;
            for(int j = 0; j < _image[i].size();j++) {
                copy[j][sz-i] = _image[i][j];
            }
        }
        std::swap(copy,_image);
    }
    
    void ImageTile::displayImage(bool withSides) const {
        int i{1};
        if(withSides) {
            cout << sides[TOP] << endl;
        }
        
        for(const auto& line : _image) {
            if(withSides)
                cout << sides[LEFT][i];
            cout << line;
            if(withSides) {
                cout << sides[RIGHT][i++];
            }
            cout << endl;
        }
        if(withSides) {
            cout << sides[BOTTOM] << endl;
        }
    }
    
    int32_t ImageTile::countHash() const {
        int32_t sum{0};
        for(const auto& row : _image) {
            sum += std::count(row.begin(), row.end(), '#');
        }
        return sum;
    }
    
    int32_t ImageTile::countSeaMonsters() {
        vector<string> monster {
            "                  # ",
            "#    ##    ##    ###",
            " #  #  #  #  #  #   "
        };
        if(_image.front().size() < monster.front().size()) {
            return 0;
        }
        vector<vector<size_t>> monsterIdx{};
        for(const auto& s : monster) {
            vector<size_t> idxs{};
            size_t idx{0};
            while((idx = s.find("#",idx)) != string::npos) {
                idxs.push_back(idx++);
            }
            monsterIdx.push_back(idxs);
//            printVector(idxs);
        }
        auto limit = _image.front().size()-monster.front().size();
        auto itr = _image.begin();
        auto total{0};
        while(itr != _image.end()-monster.size()) {
            for(size_t i = 0; i < limit;i++) {
                bool found = true;
                for(size_t j = 0;found && j < monster.size(); j++) {
                    for(const auto& idx : monsterIdx[j]) {
                        if((itr+j)->at(idx+i) != '#') {
                            found = false;
                        }
                    }
                }
                if(found) {
                    total++;
                    for(size_t j = 0;found && j < monster.size(); j++) {
                        for(const auto& idx : monsterIdx[j]) {
                            (*(itr+j))[(idx+i)] = 'O';
                        }
                    }
                }
            }
            itr++;
        }
        return total;
    }
    
    std::vector<ImageTile> tileFactory(const std::vector<std::string>& input) {
        std::vector<ImageTile> itv{};
        itv.reserve(1+input.size()/12);
        auto itr = input.begin();
        while(itr < input.end()) {
            auto tile = vector<string>(itr,itr+11);
            ImageTile t{tile};
            itv.push_back(t);
            t.rotateClockwise();
            itv.push_back(t);
            t.rotateClockwise();
            itv.push_back(t);
            t.rotateClockwise();
            itv.push_back(t);
            ImageTile tf{tile};
            tf.flip();
            itv.push_back(tf);
            tf.rotateClockwise();
            itv.push_back(tf);
            tf.rotateClockwise();
            itv.push_back(tf);
            tf.rotateClockwise();
            itv.push_back(tf);
            itr+=12;
        }
        return itv;
    }
    
    int64_t findFourCorners(const std::vector<ImageTile>& tiles) {
        unordered_map<int32_t, unordered_set<int32_t>> tileMatchCounts{};
        for(const auto& tile : tiles) {
            for(const auto& tileCmp : tiles) {
                if(tile.tileId != tileCmp.tileId) {
                    if(tile.isPossibleNeighbor(tileCmp)) {
                        tileMatchCounts[tile.tileId].insert(tileCmp.tileId);
                    }
                }
            }
        }
        int64_t product{1};
        for(const auto& kvp : tileMatchCounts) {
//            cout << kvp.first << ":" << kvp.second << endl;
            if(kvp.second.size() == 2) {
                product *= kvp.first;
            }
        }
        return product;
    }
    
    void buildLargeImage(const std::vector<ImageTile>& tiles, const unordered_map<string,vector<string>>& imageMap, unordered_set<int32_t>& processed, std::vector<ImageTile>& used, const std::string& tName) {
        auto itr = tiles.begin();
        while(itr != tiles.end() && itr->tileName != tName) {
            itr++;
        }
        if(processed.count(itr->tileId)==0) {
            processed.insert(itr->tileId);
            used.push_back(*itr);
            for(const auto& tNeighbor : imageMap.at(itr->tileName)) {
                buildLargeImage(tiles, imageMap, processed, used, tNeighbor);
            }
        }
    }
    
    void arrangeTiles(const std::vector<ImageTile>& used, unordered_set<int32_t>& processed, const std::string& tName,std::vector<std::vector<int32_t>>& arrangement, std::pair<int32_t,int32_t> coords) {
        auto itr = used.begin();
        while(itr != used.end() && itr->tileName != tName) {
            itr++;
        }
        if(processed.count(itr->tileId) == 0) {
            arrangement[coords.second][coords.first] = itr->tileId;
            processed.insert(itr->tileId);
            
            for(const auto& t : used) {
                if(t.tileId != itr->tileId) {
                    if(itr->isPossibleNeighbor(t)) {
                        auto loc = itr->neighborLocation(t);
                        std::pair<int32_t,int32_t> p{coords};
                        if(loc == TOP) {
                            p.second--;
                        } else if(loc == RIGHT) {
                            p.first++;
                        } else if(loc == BOTTOM) {
                            p.second++;
                        } else if(loc == LEFT) {
                            p.first--;
                        } else {
                            cout << "ERROR in arragement\n";
                        }
                        arrangeTiles(used, processed, t.tileName, arrangement, p);
                    }
                }
            }
        }
    }
    
    ImageTile findArrangement(const std::vector<ImageTile>& tiles) {
        std::vector<std::vector<int32_t>> arrangement{};
        unordered_map<int32_t, std::unordered_set<int32_t>> tileMatchCounts{};
        for(const auto& tile : tiles) {
            for(const auto& tileCmp : tiles) {
                if(tile.tileId != tileCmp.tileId) {
                    if(tile.isPossibleNeighbor(tileCmp)) {
                        tileMatchCounts[tile.tileId].insert(tileCmp.tileId);
                    }
                }
            }
        }
        
        unordered_map<string,vector<string>> x;
        for(const auto& kvp : tileMatchCounts) {
            for(const auto& i : kvp.second) {
                for(const auto& tile : tiles) {
                    for(const auto& tileCmp : tiles) {
                        if(tile.tileId == kvp.first &&
                           tileCmp.tileId == i) {
                            if(tile.isPossibleNeighbor(tileCmp)) {
                                x[tile.tileName].push_back(tileCmp.tileName);
                            }
                        }
                    }
                }
            }
        }
        unordered_set<int32_t> processed{};
        vector<ImageTile> used;
        buildLargeImage(tiles, x, processed, used, x.begin()->first);
//        for(const auto& t : used) {
//            cout << t.tileName << endl;
//        }
        auto l = sqrt(used.size());
        for(int i = 0; i < l; i++) {
            arrangement.push_back(vector<int32_t>(l,0));
//            printVector(arrangement.back());
        }
        
        auto itr = used.begin();
        while(itr != used.end() && x[itr->tileName].size() != 2) {
            itr++;
        }
        vector<uint8_t> border{};
        for(const auto& t : used) {
            if(t.tileId != itr->tileId) {
                if(itr->isPossibleNeighbor(t)) {
                    border.push_back(itr->neighborLocation(t));
                }
            }
        }
        std::pair<int32_t,int32_t> coords{0,0};
        std::sort(border.begin(),border.end());
        if(border.front() == RIGHT && border.back() == BOTTOM) {
            //0,0
        } else if(border.front() == BOTTOM && border.back() == LEFT) {
            coords.first = l-1;
        } else if(border.front() == TOP && border.back() == LEFT) {
            coords.first = l-1;
            coords.second = l-1;
        } else if(border.front() == TOP && border.back() == RIGHT) {
            coords.second = l-1;
        } else {
            cout << "ERROR in coords\n";
        }
        processed.clear();
        arrangeTiles(used, processed, itr->tileName, arrangement, coords);
//        for(const auto& v : arrangement) {
//            printVector(v);
//        }
        
        std::vector<std::string> bigImage{};
        for(const auto& row : arrangement) {
            std::vector<std::string> pImage{};
            for(const auto& iid : row) {
                auto itr = used.begin();
                while(itr != used.end() && itr->tileId != iid) {
                    itr++;
                }
//                cout << itr->tileName << endl;
//                itr->displayImage(true);
                if(pImage.size() == 0) {
                    pImage = itr->getImage();
                } else {
                    auto pItr = pImage.begin();
                    for(const auto& s : itr->getImage()) {
                        pItr->append(s);
                        pItr++;
                    }
                }
            }
            for(const auto& newRow : pImage) {
                bigImage.push_back(newRow);
            }
        }
        ImageTile finalImage{bigImage,222};
//        finalImage.displayImage(true);
        cout << finalImage.countHash()  << endl;

        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 4; j++) {
                if(finalImage.countSeaMonsters() > 0) {
                    finalImage.displayImage();
//                    cout << finalImage.countHash()  << endl;
                }
                finalImage.rotateClockwise();
//                finalImage.displayImage(true);
            }
            finalImage.flip();
//            finalImage.displayImage(true);
        }

//        cout << finalImage.countHash()  << endl;
        return finalImage;
    }
}
