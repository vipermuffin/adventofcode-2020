//
//  Advent of Code 2020 Solutions: Day 7
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/06/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

namespace AocDay07 {
//Function Definitions
    using BagDictionary = std::unordered_map<std::string, std::vector<std::pair<std::string,int32_t>>>;
    void updateBagDatabase(const std::string& line, BagDictionary& inDb, BagDictionary& outDb);
    void findContainingBags(const BagDictionary& outDb,std::unordered_set<std::string>&,const std::string& bagName);
    int32_t findNestedBags(const BagDictionary& inDb,const std::string& bagName);
}
