//
//  Advent of Code 2020 Tests: Day 6
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/05/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day06.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay06{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay06;

TEST(Y2020_SolveDay6, FinalSolutionPartA) {
    EXPECT_EQ("7120", solvea());
}

TEST(Y2020_SolveDay6, FinalSolutionPartB) {
    EXPECT_EQ("3570", solveb());
}

TEST(Y2020_Day6Example,Test1) {
    int x = 0;
    EXPECT_EQ(0,x);
}

TEST(Y2020_Day6Example,Test2) {
    int x = 0;
    EXPECT_EQ(0,x);
}

TEST(Y2020_Day6Example,Test3) {
    int x = 0;
    EXPECT_EQ(0,x);
}
