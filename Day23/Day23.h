//
//  Advent of Code 2020 Solutions: Day 23
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/22/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <list>

namespace AocDay23 {
//Function Definitions
    std::string playGame(std::list<int32_t>& order,int32_t rounds);
    int64_t playGame2(std::list<int32_t>& order,int32_t rounds);
}
