//
//  Advent of Code 2020 Solutions: Day 17
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/17/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace AocDay17 {
//Function Definitions
    typedef union {
        uint64_t all;
        int16_t  val[4];
    } PointInfo;
    constexpr int16_t X = 0;
    constexpr int16_t Y = 1;
    constexpr int16_t Z = 2;
    constexpr int16_t U = 3;
    using PointMap = std::unordered_map<uint64_t, bool>;
    
    PointMap initMap(const std::vector<std::string>&);
    uint64_t performCycle(PointMap& points, bool use4d = false);
}
