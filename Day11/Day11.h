//
//  Advent of Code 2020 Solutions: Day 11
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/10/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay11 {
//Function Definitions
    std::string convertMapToString(const std::vector<std::string>&);
    void performSeating(std::vector<std::string>&, const bool useView = false);
    int32_t countAdjacentOccupiedSeats(const std::vector<std::string>&, const int32_t,const int32_t,const bool);
}
