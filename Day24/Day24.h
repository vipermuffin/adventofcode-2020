//
//  Advent of Code 2020 Solutions: Day 24
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/26/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay24 {
//Function Definitions
    std::vector<std::string> parseDirections(const std::string& line);
    int32_t flipTiles(const std::vector<std::string>& lines);
    int32_t flipTilesWaitXDays(const std::vector<std::string>& lines,const int32_t days);
}
