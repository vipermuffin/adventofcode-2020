//
//  Advent of Code 2020 Solutions: Day 5
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/04/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day05.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.


using namespace std;
namespace AocDay05 {

    static const std::string InputFileName = "Day05.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        int32_t max = 0;
        for(const auto& line : input) {
            auto x = getSeatId(line);
            if(x > max) {
                max = x;
            }
        }
		return to_string(max);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        vector<int32_t> x{};
        
        for(const auto& line : input) {
            x.push_back(getSeatId(line));
        }
        std::sort(x.begin(), x.end());
        auto itr = x.begin();
        auto lastVal = *itr++;
        while(itr != x.end()) {
            if(*itr != (lastVal+1) && (*itr == (lastVal+2))) {
                return to_string(lastVal+1);
            }
            lastVal = *itr++;
        }
		return "---";
    }

    int32_t getSeatId(const std::string& bPass) {
        
        int32_t min{0},max{127},col{0},seat{0};
        
        for(auto i = 0; i < 7; i++) {
            if(bPass[i] == 'F') {
                max = (max+min)/2;
                col = max;
            } else if (bPass[i] == 'B') {
                min = (max+min+1)/2;
                col = min;
            }
        }
        
        min = 0;
        max = 7;
        for(auto i = 7; i < 10; i++) {
            if(bPass[i] == 'L') {
                max = (max+min)/2;
                seat = max;
            } else if (bPass[i] == 'R') {
                min = (max+min+1)/2;
                seat = min;
            }
        }

        return col*8+seat;
    }
}
