//
//  Advent of Code 2020 Tests: Day 1
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 11/30/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day01.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay01{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay01;

TEST(Y2020_SolveDay1, FinalSolutionPartA) {
    EXPECT_EQ("1013211", solvea());
}

TEST(Y2020_SolveDay1, FinalSolutionPartB) {
    EXPECT_EQ("13891280", solveb());
}

