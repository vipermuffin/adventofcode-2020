//
//  Advent of Code 2020 Solutions: Day 17
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/17/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day17.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.


using namespace std;
namespace AocDay17 {
    
    static const std::string InputFileName = "Day17.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto map = initMap(input);
        uint64_t x;
        for(int i = 0; i < 6; i++) {
            x = performCycle(map);
        }
		return to_string(x);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto map = initMap(input);
        uint64_t x;
        for(int i = 0; i < 6; i++) {
            x = performCycle(map,true);
        }
        return to_string(x);
    }
    
    PointMap initMap(const std::vector<std::string>& input) {
        unordered_map<uint64_t, bool> m{};
        PointInfo tmp;
        for(int16_t y = 0; y < input.size(); y++) {
            for(int16_t x = 0; x < input[y].size(); x++) {
                if(input[y][x] == '#') {
                    tmp.all = 0;
                    tmp.val[X] = x;
                    tmp.val[Y] = y;
                    m[tmp.all] = true;
                }
            }
        }
        return m;
    }

    uint64_t performCycle(PointMap& points, bool use4d) {
        vector<uint64_t> pointsToUpdate{};
        vector<std::pair<uint64_t,bool>> updated{};
        auto sz = points.size();
        sz *= 80;
        const int16_t umin = use4d ? -1 : 0;
        const int16_t umax = use4d ? 2 : 1;
        pointsToUpdate.reserve(sz);
        updated.reserve(sz);
        //Check if Point should change state and build list of new points to go through
        for(const auto& kvp : points) {
            uint16_t count{0};
            for(int16_t x = -1; x < 2; x++) {
                for(int16_t y = -1; y < 2; y++) {
                    for(int16_t z = -1; z < 2; z++) {
                        for(int16_t u = umin; u < umax; u++) {
                            if(!(x==0 && y==0 && z==0 && u==0)) {
                                PointInfo tmp{kvp.first};
                                tmp.val[X] += x;
                                tmp.val[Y] += y;
                                tmp.val[Z] += z;
                                tmp.val[U] += u;
                                pointsToUpdate.push_back(tmp.all);
                                if(points.count(tmp.all) > 0) {
                                    count += points[tmp.all] ? 1 : 0;
                                }
                            }
                        }
                    }
                }
            }
            bool updatedVal = kvp.second;
            if(kvp.second) {
                if(count < 2 || count > 3) {
                    updatedVal = false;
                }
            } else {
                if(count == 3) {
                    updatedVal = true;
                }
            }
            updated.emplace_back(kvp.first,updatedVal);
        }
        std::sort(pointsToUpdate.begin(), pointsToUpdate.end());
        auto itr = pointsToUpdate.begin();
        while(itr!=pointsToUpdate.end()) {
            uint16_t count{0};
            for(int16_t x = -1; x < 2; x++) {
                for(int16_t y = -1; y < 2; y++) {
                    for(int16_t z = -1; z < 2; z++) {
                        for(int16_t u = umin; u < umax; u++) {
                            if(!(x==0 && y==0 && z==0 && u == 0)) {
                                PointInfo tmp{*itr};
                                tmp.val[X] += x;
                                tmp.val[Y] += y;
                                tmp.val[Z] += z;
                                tmp.val[U] += u;
                                if(points.count(tmp.all) > 0) {
                                    count += points[tmp.all] ? 1 : 0;
                                }
                            }
                        }
                    }
                }
            }
            bool updatedVal = points[*itr];
            if(points[*itr]) {
                //Active
                if(count < 2 || count > 3) {
                    updatedVal = false;
                }
            } else {
                if(count == 3) {
                    updatedVal = true;
                }
            }
            updated.emplace_back(*itr,updatedVal);
            itr++;
            while(itr != pointsToUpdate.end() && *(itr-1) == *itr) {
                itr++;
            }
        }
        
        //Update Map
        for(const auto point : updated) {
            points[point.first] = point.second;
        }
        uint64_t activePoints = count_if(points.begin(),points.end(),[](std::pair<uint64_t,bool> x)->bool{return x.second;});
        return activePoints;
    }
}
