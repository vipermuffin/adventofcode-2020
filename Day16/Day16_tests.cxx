//
//  Advent of Code 2020 Tests: Day 16
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/15/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day16.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>


namespace AocDay16{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay16;

TEST(Y2020_SolveDay16, FinalSolutionPartA) {
    EXPECT_EQ("22000", solvea());
}

TEST(Y2020_SolveDay16, FinalSolutionPartB) {
    EXPECT_EQ("410460648673", solveb());
}

TEST(Y2020_Day16Example,Test1) {
    TicketDb x{};
    string rule{"class: 1-3 or 5-7"};
    parseTicketRule(rule, x);
    ASSERT_EQ(1,x.size());
    auto itr = x.begin();
    ASSERT_EQ(2,itr->second.size());
    EXPECT_EQ("class", itr->first);
    EXPECT_EQ(1, itr->second[0].first);
    EXPECT_EQ(5, itr->second[1].first);
    EXPECT_EQ(3, itr->second[0].second);
    EXPECT_EQ(7, itr->second[1].second);
}

TEST(Y2020_Day16Example,Test2a) {
    TicketDb x{};
    string rule{"class: 1-3 or 5-7"};
    parseTicketRule(rule, x);
    auto ranges = buildRangeList(x);
    ASSERT_EQ(2,ranges.size());
    EXPECT_EQ(1, ranges.front().first);
    EXPECT_EQ(3, ranges.front().second);
    EXPECT_EQ(5, ranges.back().first);
    EXPECT_EQ(7, ranges.back().second);
}
TEST(Y2020_Day16Example,Test2b) {
    TicketDb x{};
    string rule{"class: 1-6 or 5-7"};
    parseTicketRule(rule, x);
    auto ranges = buildRangeList(x);
    ASSERT_EQ(1,ranges.size());
    EXPECT_EQ(1, ranges.front().first);
    EXPECT_EQ(7, ranges.front().second);
}

TEST(Y2020_Day16Example,Test3) {
    TicketDb x{};
    parseTicketRule("class: 1-3 or 5-7",x);
    parseTicketRule("row: 6-11 or 33-44",x);
    parseTicketRule("seat: 13-40 or 45-50",x);
    auto ranges = buildRangeList(x);
    std::vector<int32_t> invalid{};
    EXPECT_TRUE(isValidList({7,3,47}, ranges, invalid));
    EXPECT_FALSE(isValidList({40,4,50}, ranges,invalid));
    EXPECT_FALSE(isValidList({55,2,20}, ranges, invalid));
    EXPECT_FALSE(isValidList({38,6,12}, ranges, invalid));
    ASSERT_EQ(3, invalid.size());
    EXPECT_EQ(4, invalid[0]);
    EXPECT_EQ(55, invalid[1]);
    EXPECT_EQ(12, invalid[2]);
}
