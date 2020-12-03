//
//  Advent of Code 2020 Tests: Day 3
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/02/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day03.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay03{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay03;

TEST(Y2020_SolveDay3, FinalSolutionPartA) {
    EXPECT_EQ("209", solvea());
}

TEST(Y2020_SolveDay3, FinalSolutionPartB) {
    EXPECT_EQ("1574890240", solveb());
}

TEST(Y2020_Day3Example,Test1) {
    int x = 0;
    EXPECT_EQ(7,x);
}

TEST(Y2020_Day3Example,Test2) {
    int x = 0;
    EXPECT_EQ(336,x);
}

TEST(Y2020_Day3Example,Test3) {
    int x = 0;
    EXPECT_EQ(0,x);
}
