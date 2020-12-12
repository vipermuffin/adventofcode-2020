//
//  Advent of Code 2020 Solutions: Day 11
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/10/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day11.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <functional> //std::function
#include <sstream>
#include <unordered_map>



using namespace std;
namespace AocDay11 {
    int32_t countOccupiedSeatsInViewForSlope(const std::vector<std::string>& grid, const int32_t row, const int32_t col, int32_t dx, int32_t dy);

    static const std::string InputFileName = "Day11.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto s = convertMapToString(input);
        auto previousS{s};
        do {
            std::swap(s,previousS);
            performSeating(input, false);
            s = convertMapToString(input);
        }while(s!=previousS);
        auto x = std::count(s.begin(),s.end(),'#');
        return to_string(x);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto s = convertMapToString(input);
        auto previousS{s};
        do {
            std::swap(s,previousS);
            performSeating(input, true);
            s = convertMapToString(input);
        }while(s!=previousS);
        auto x = std::count(s.begin(),s.end(),'#');
		return to_string(x);
    }
    
    int32_t countAdjacentOccupiedSeats(const std::vector<std::string>& grid, const int32_t row, const int32_t col, const bool useView) {
        int32_t total{0};
        for(int x = -1;x <= 1; x++) {
            for(int y = -1; y <= 1;y++) {
                if(!(x == 0 && y == 0)) {
                    if(useView) {
                        total += countOccupiedSeatsInViewForSlope(grid, row, col, x, y);
                    } else {
                        auto dx = col+x;
                        auto dy = row+y;
                        if((dy >= 0 && dy < grid.size()) &&
                           (dx >= 0 && dx < grid[dy].size())) {
                            total += grid[dy][dx] == '#' ? 1 : 0;
                        }
                    }
                }
            }
        }
        return total;
    }
    
    int32_t countOccupiedSeatsInViewForSlope(const std::vector<std::string>& grid, const int32_t row, const int32_t col, int32_t dx, int32_t dy) {
        auto dRow{row+dy};
        auto dCol{col+dx};
        
        while((dRow >= 0 && dRow < grid.size()) &&
              (dCol >= 0 && dCol < grid[dRow].size()) &&
              (grid[dRow][dCol] == '.')) {
            dRow += dy;
            dCol += dx;
        }
        if((dRow >= 0 && dRow < grid.size()) &&
           (dCol >= 0 && dCol < grid[dRow].size())) {
            return grid[dRow][dCol] == '#' ? 1 : 0;
        } else {
            return 0;
        }
    }
    
    void performSeating(std::vector<std::string>& map, const bool useView) {
        const int32_t limit{useView ? 5 : 4};
        vector<string> copy{map};
        unordered_map<char, function<void(int32_t,int32_t,int32_t)>> ops{
            {'.',[](int32_t,int32_t,int32_t){/*nothing required*/}},
            {'L',[&](int32_t val,int32_t x,int32_t y){if(val==0) {copy[y][x]='#';}}},
            {'#',[&](int32_t val,int32_t x,int32_t y){if(val>=limit) {copy[y][x]='L';}}}
        };
        
        for(int row = 0; row < map.size(); row++) {
            for(int col = 0; col < map[row].size(); col++) {
                int32_t x = countAdjacentOccupiedSeats(map, row, col, useView);
                ops[map[row][col]](x,col,row);
            }
        }
        std::swap(map, copy);
    }
    
    std::string convertMapToString(const std::vector<std::string>& map) {
        stringstream ss{};
        for(const auto& line : map) {
            ss << line;
        }
        return ss.str();
    }

}
