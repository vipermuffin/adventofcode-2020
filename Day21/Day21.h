//
//  Advent of Code 2020 Solutions: Day 21
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/20/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace AocDay21 {
//Function Definitions
    using FoodDb = std::unordered_map<std::string,std::vector<std::string>>;
    using FoodPairList = std::vector<std::pair<std::string,std::string>>;
    FoodDb parseFoodList(const std::vector<std::string>& input);
    void parseFoodRow(const std::string& input, FoodDb& db);
    FoodPairList determineFoodName(const FoodDb& db);
    int32_t countNonAllergens(const std::vector<std::string>& input);
    std::string produceCanonicalDangerousList(const std::vector<std::string>& input);
}
