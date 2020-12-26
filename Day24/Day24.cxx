//
//  Advent of Code 2020 Solutions: Day 24
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/26/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day24.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <regex>
#include <unordered_map>

using namespace std;
namespace AocDay24 {

    static const std::string InputFileName = "Day24.txt";
    using TileMap = std::unordered_map<uint64_t, bool>;
    struct pos_t {
        int32_t x;
        int32_t y;
    };
    union Coord {
        uint64_t all;
        pos_t pos;
    };
    
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);

		return to_string(flipTiles(input));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

		return to_string(flipTilesWaitXDays(input, 100));
    }

    std::vector<std::string> parseDirections(const std::string& line) {
        vector<string> directions{};
        directions.reserve(line.size());
        regex input_regex("(se|sw|ne|nw|e|w)");
        auto iBegin = sregex_iterator(line.begin(),line.end(),input_regex);
        auto iEnd = std::sregex_iterator();
        while(iBegin != iEnd) {
            std::smatch match = *iBegin;
            if(match.size() > 0) {
                directions.push_back(match[0]);
            }
            iBegin++;
        }
        return directions;
    }
    
    int32_t flipTiles(const std::vector<std::string>& lines) {
        Coord xy;
        unordered_map<string, uint64_t> dirDelta{};
        xy.pos.x = 4;  xy.pos.y = 0;  dirDelta["e"] = xy.all;
        xy.pos.x = -4; xy.pos.y = 0;  dirDelta["w"] = xy.all;
        xy.pos.x = 2;  xy.pos.y = -3; dirDelta["se"] = xy.all;
        xy.pos.x = 2;  xy.pos.y = 3;  dirDelta["ne"] = xy.all;
        xy.pos.x = -2; xy.pos.y = 3;  dirDelta["nw"] = xy.all;
        xy.pos.x = -2; xy.pos.y = -3; dirDelta["sw"] = xy.all;
        
        TileMap tiles{};
        for(const auto& line : lines) {
            xy.all = 0;
            auto dirs = parseDirections(line);
            for(const auto& dir : dirs) {
                Coord tmp;
                tmp.all = dirDelta[dir];
                xy.pos.x += tmp.pos.x;
                xy.pos.y += tmp.pos.y;
            }
            tiles[xy.all] = !tiles[xy.all];
        }
        return count_if(tiles.begin(),tiles.end(),[](const std::pair<uint64_t,bool>& p){return p.second;});
    }
    
    void checkAndUpdateTile(TileMap& tiles, TileMap& tiles_cpy, TileMap& checked, uint64_t pos) {
        if(checked[pos]) {
            return;
        } else {
            checked[pos] = true;
        }
        Coord xy;
        vector<uint64_t> adjPosDelta{};
        xy.pos.x = 4;  xy.pos.y = 0;  adjPosDelta.push_back(xy.all);
        xy.pos.x = -4; xy.pos.y = 0;  adjPosDelta.push_back(xy.all);
        xy.pos.x = 2;  xy.pos.y = -3; adjPosDelta.push_back(xy.all);
        xy.pos.x = 2;  xy.pos.y = 3;  adjPosDelta.push_back(xy.all);
        xy.pos.x = -2; xy.pos.y = 3;  adjPosDelta.push_back(xy.all);
        xy.pos.x = -2; xy.pos.y = -3; adjPosDelta.push_back(xy.all);
        vector<uint64_t> neighbors{};
        bool checkNeighbors = false;
        for(const auto& delta : adjPosDelta) {
            Coord tmp, dTmp;
            tmp.all = pos;
            dTmp.all = delta;
            tmp.pos.x += dTmp.pos.x;
            tmp.pos.y += dTmp.pos.y;
            neighbors.push_back(tmp.all);
        }
        auto blackCount = count_if(neighbors.begin(),neighbors.end(),[&tiles](const uint64_t xy){ bool exist = tiles.count(xy) > 0; return exist  ? tiles[xy] : false;});
        bool tileExists = tiles.count(pos) > 0;
        if(tileExists && tiles[pos]) {
            if(blackCount == 0 || blackCount > 2) {
                tiles_cpy[pos] = false;
            }
        } else {
            if(blackCount == 2) {
                tiles_cpy[pos] = true;
            }
            checkNeighbors = blackCount != 0;
        }
        
        if(checkNeighbors) {
            for(const auto p : neighbors) {
                checkAndUpdateTile(tiles, tiles_cpy, checked, p);
            }
        }
    }
    
    int32_t flipTilesWaitXDays(const std::vector<std::string>& lines,const int32_t days) {
        Coord xy;
        unordered_map<string, uint64_t> dirDelta{};
        xy.pos.x = 4;  xy.pos.y = 0;  dirDelta["e"] = xy.all;
        xy.pos.x = -4; xy.pos.y = 0;  dirDelta["w"] = xy.all;
        xy.pos.x = 2;  xy.pos.y = -3; dirDelta["se"] = xy.all;
        xy.pos.x = 2;  xy.pos.y = 3;  dirDelta["ne"] = xy.all;
        xy.pos.x = -2; xy.pos.y = 3;  dirDelta["nw"] = xy.all;
        xy.pos.x = -2; xy.pos.y = -3; dirDelta["sw"] = xy.all;
        
        //init map
        TileMap tiles{};
        for(const auto& line : lines) {
            xy.all = 0;
            auto dirs = parseDirections(line);
            for(const auto& dir : dirs) {
                Coord tmp;
                tmp.all = dirDelta[dir];
                xy.pos.x += tmp.pos.x;
                xy.pos.y += tmp.pos.y;
            }
            tiles[xy.all] = !tiles[xy.all];
        }
        
        vector<uint64_t> adjPosDelta{};
        xy.pos.x = 4;  xy.pos.y = 0;  adjPosDelta.push_back(xy.all);
        xy.pos.x = -4; xy.pos.y = 0;  adjPosDelta.push_back(xy.all);
        xy.pos.x = 2;  xy.pos.y = -3; adjPosDelta.push_back(xy.all);
        xy.pos.x = 2;  xy.pos.y = 3;  adjPosDelta.push_back(xy.all);
        xy.pos.x = -2; xy.pos.y = 3;  adjPosDelta.push_back(xy.all);
        xy.pos.x = -2; xy.pos.y = -3; adjPosDelta.push_back(xy.all);
        for(int i = 0; i < days;i++) {
            TileMap cpy{tiles};
            TileMap checked{};
            for(const auto kvp : tiles) {
                checkAndUpdateTile(tiles, cpy, checked, kvp.first);
            }
            std::swap(cpy,tiles);
        }
        return count_if(tiles.begin(),tiles.end(),[](const std::pair<uint64_t,bool>& p){return p.second;});
    }
}
