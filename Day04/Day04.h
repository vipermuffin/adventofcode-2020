//
//  Advent of Code 2020 Solutions: Day 4
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/03/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace AocDay04 {
//Function Definitions
    void buildPassportStrings(const std::vector<std::string>&input,std::vector<std::string>&output);
    void updatePassportMap(const std::string &input,std::unordered_map<std::string,std::string>&output);
    bool passportIsValid(const std::unordered_map<std::string, std::string>&input);
    bool passportIsValid2(const std::unordered_map<std::string, std::string>&input);
}
