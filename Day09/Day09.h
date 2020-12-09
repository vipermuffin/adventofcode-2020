//
//  Advent of Code 2020 Solutions: Day 9
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/08/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay09 {
//Function Definitions
    
    bool isValid(const std::vector<int64_t>&,const int64_t val);
    int64_t findInvalidVal(const std::vector<int64_t>&, const int64_t preamble);
    int64_t findInvalidValMatch(const std::vector<int64_t>& vals, const int64_t match);
}
