//
//  Advent of Code 2020 Solutions: Day 22
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/21/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <list>
#include <unordered_set>
#include <unordered_map>

namespace AocDay22 {
//Function Definitions
    int64_t playGame(std::list<int32_t> p1, std::list<int32_t> p2);
    uint32_t playGame(std::vector<int32_t> p1, std::vector<int32_t> p2);
    std::pair<int64_t,bool> playGame2(std::vector<int32_t>& p1, std::vector<int32_t>& p2, std::unordered_map<size_t,std::pair<int64_t,bool>>& cache);
}
