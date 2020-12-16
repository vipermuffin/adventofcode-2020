//
//  Advent of Code 2020 Tests: Day 15
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/14/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day15.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay15{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay15;

TEST(Y2020_SolveDay15, FinalSolutionPartA) {
    EXPECT_EQ("376", solvea());
}

TEST(Y2020_SolveDay15, FinalSolutionPartB) {
    EXPECT_EQ("323780", solveb());
}

TEST(Y2020_Day15Example,Test0) {
    vector<int32_t> v {0,3,6}; 
    auto x = findNumberSpoken(v, 10);
    EXPECT_EQ(0,x);
}

TEST(Y2020_Day15Example,Test1) {
    vector<int32_t> v {1,3,2};
    auto x = findNumberSpoken(v, 2020);
    EXPECT_EQ(1,x);
}

TEST(Y2020_Day15Example,Test2) {
    vector<int32_t> v {2,1,3};
    auto x = findNumberSpoken(v, 2020);
    EXPECT_EQ(10,x);
}

TEST(Y2020_Day15Example,Test3) {
    vector<int32_t> v {1,2,3};
    auto x = findNumberSpoken(v, 2020);
    EXPECT_EQ(27,x);
}

TEST(Y2020_Day15Example,Test4) {
    vector<int32_t> v {2,3,1};
    auto x = findNumberSpoken(v, 2020);
    EXPECT_EQ(78,x);
}

TEST(Y2020_Day15Example,Test5) {
    vector<int32_t> v {3,2,1};
    auto x = findNumberSpoken(v, 2020);
    EXPECT_EQ(438,x);
}

TEST(Y2020_Day15Example,Test6) {
    vector<int32_t> v {3,1,2};
    auto x = findNumberSpoken(v, 2020);
    EXPECT_EQ(1836,x);
}
