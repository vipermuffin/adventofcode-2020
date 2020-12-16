//
//  Advent of Code 2020 Solutions: Day 13
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/12/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay13 {
//Function Definitions
    int32_t findEarliestBus(const std::string& schedule, const int32_t minTime);
    int64_t findEarliestTimestamp(const std::string& schedule, const int64_t initVal = 0);

}
