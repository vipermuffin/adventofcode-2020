//
//  Advent of Code 2020 Solutions: Day 15
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/14/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day15.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <unordered_map>


using namespace std;
namespace AocDay15 {

    static const std::string InputFileName = "Day15.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto start = parseCsvLineForNum(input[0]);

		return to_string(findNumberSpoken(start, 2020));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto start = parseCsvLineForNum(input[0]);
        
        return to_string(findNumberSpoken(start, 30000000));
    }

    int32_t findNumberSpoken(const std::vector<int32_t>& startList, const int32_t num) {
        int32_t turn{1};
        //Since you can't have a number larger than the number of turns,
        //A vector can be used with a size of the target num turns
        vector<std::pair<int32_t,int32_t>> x{};
        x.resize(num);

        for(const auto& val : startList) {
            x[val] = make_pair(turn++,0);
        }
        int32_t lastVal = startList.back();
        while(turn <= num) {
            int32_t newVal = x[lastVal].second == 0 ? 0 : x[lastVal].first - x[lastVal].second;
            x[newVal].second = x[newVal].first;
            x[newVal].first = turn++;
            lastVal = newVal;
        }
        
        return lastVal;
    }
}
