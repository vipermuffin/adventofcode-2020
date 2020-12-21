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
//#include <math.h> //sqrt
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

		return "---";
    }

    ImageTile::ImageTile(std::vector<std::string> image) {
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
//         for(int i = 0; i < sides.size(); i++) {
//            for(int j = 0; j < it.sides.size(); j++) {
//                if(sides[i] == it.sides[j]) {
//                    neighbor = true;
//                    cout << tileName << "{" << i << "}<-->" << it.tileName << "{" << j << "}" << endl;
//                    break;
//                }
//            }
//        }
        return neighbor;
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
    
    std::vector<std::vector<int32_t>> findArrangement(const std::vector<ImageTile>& tiles) {
        std::vector<std::vector<int32_t>> arrangement{};
        map<int32_t, std::vector<int32_t>> tileMatchCounts{};
        for(const auto& tile : tiles) {
            for(const auto& tileCmp : tiles) {
                if(tile.tileId != tileCmp.tileId) {
                    if(tile.isPossibleNeighbor(tileCmp)) {
                        tileMatchCounts[tile.tileId].push_back(tileCmp.tileId);
                    }
                }
            }
        }
        for(const auto& kvp : tileMatchCounts) {
            cout << "Tile " << kvp.first << ":";
            printVector(kvp.second);
        }
        return arrangement;
    }
}
