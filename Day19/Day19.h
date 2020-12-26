//
//  Advent of Code 2020 Solutions: Day 19
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/18/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

namespace AocDay19 {
//Function Definitions
    using RuleBook = std::unordered_map<int32_t, std::vector<std::string>>;
    using tempRuleBook = std::unordered_map<int32_t, std::vector<std::pair<int32_t,int32_t>>>;
    const int32_t INVALID{-222};
    
    RuleBook ruleBuilder(const std::vector<std::string>&);
    void readRule(const std::string&,RuleBook&,tempRuleBook&);
    
}
