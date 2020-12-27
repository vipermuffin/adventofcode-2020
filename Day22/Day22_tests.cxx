//
//  Advent of Code 2020 Tests: Day 22
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/21/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day22.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay22{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay22;

TEST(Y2020_SolveDay22, FinalSolutionPartA) {
    EXPECT_EQ("35202", solvea());
}

TEST(Y2020_SolveDay22, FinalSolutionPartB) {
    EXPECT_EQ("32317", solveb());
}

TEST(Y2020_Day22Example,Test2) {
    vector<int32_t> p1 {9,2,6,3,1};
    vector<int32_t> p2 {5,8,4,7,10};
    EXPECT_EQ(306,playGame(p1, p2));
}

TEST(Y2020_Day22Example,Test3) {
    vector<int32_t> p1 {9,2,6,3,1};
    vector<int32_t> p2 {5,8,4,7,10};
    unordered_map<size_t,std::pair<int64_t,bool>> cache{};
    EXPECT_EQ(291,playGame2(p1, p2, cache).first);
}

TEST(Y2020_Day22Example,Test4) {
    vector<int32_t> p1 {43,19};
    vector<int32_t> p2 {2,29,14};
    unordered_map<size_t,std::pair<int64_t,bool>> cache{};
    EXPECT_EQ(-222,playGame2(p1, p2, cache).first);
}
