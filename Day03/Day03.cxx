//
//  Advent of Code 2020 Solutions: Day 3
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/02/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day03.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <numeric> //std::accumulate


using namespace std;
namespace AocDay03 {

    static const std::string InputFileName = "Day03.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);

		return to_string(findTreesWithSlope(input, make_pair(3,1)));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        vector<pair<int32_t,int32_t>> slopes {{1,1},{3,1},{5,1},{7,1},{1,2}};
        vector<int32_t> vals{};
        
        for_each(slopes.begin(), slopes.end(),
                 [&input,&vals](std::pair<int32_t,int32_t> xy) {vals.push_back(findTreesWithSlope(input, xy));});
        
        return to_string(accumulate(vals.begin(), vals.end(), 1,multiplies<int64_t>()));
    }
    
    int32_t findTreesWithSlope(const std::vector<std::string>& treeMap, std::pair<int32_t,int32_t> slope) {
        int32_t charIdx{0}, count{0};
        auto itr = treeMap.begin()+slope.second;
        while(itr < treeMap.end()) {
            charIdx += slope.first;
            if(charIdx >= itr->size()) {
                charIdx -= itr->size();
            }
            count += (*itr)[charIdx] == '#' ? 1 : 0;
            itr+=slope.second;
        }
        return count;
    }

}
