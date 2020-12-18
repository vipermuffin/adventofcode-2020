//
//  Advent of Code 2020 Solutions: Day 16
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/15/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace AocDay16 {
//Function Definitions
    using TicketDb = std::unordered_map<std::string,std::vector<std::pair<int32_t,int32_t>>>;
    using RangeList = std::vector<std::pair<int32_t,int32_t>>;
    void parseTicketRule(const std::string& line, TicketDb& database);
    RangeList buildRangeList(const TicketDb& database);
    bool isValidList(const std::vector<int32_t>& vals,const RangeList& validRanges, std::vector<int32_t>& invalidVals);

}
