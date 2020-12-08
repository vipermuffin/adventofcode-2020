//
//  Advent of Code 2020 Tests: Day 8
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/07/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day08.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay08{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay08;

TEST(Y2020_SolveDay8, FinalSolutionPartA) {
    EXPECT_EQ("1930", solvea());
}

TEST(Y2020_SolveDay8, FinalSolutionPartB) {
    EXPECT_EQ("1688", solveb());
}

TEST(Y2020_Day8Example,Test1) {
    int x = 0;
    EXPECT_EQ(0,x);
}

TEST(Y2020_Day8Example,Test2) {
    int x = 0;
    EXPECT_EQ(0,x);
}

TEST(Y2020_Day8Example,Test3) {
    int x = 0;
    EXPECT_EQ(0,x);
}
