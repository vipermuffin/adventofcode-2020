//
//  Advent of Code 2020 Tests: Day 2
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/01/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day02.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay02{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay02;

TEST(Y2020_SolveDay2, FinalSolutionPartA) {
    EXPECT_EQ("416", solvea());
}

TEST(Y2020_SolveDay2, FinalSolutionPartB) {
    EXPECT_EQ("688", solveb());
}

TEST(Y2020_Day2Example,Test1) {
    string x{"1-3 a: abcde"};
    EXPECT_TRUE(isPasswordValid(x));
}

TEST(Y2020_Day2Example,Test2) {
    string x{"1-3 b: cdefg"};
    EXPECT_FALSE(isPasswordValid(x));
}

TEST(Y2020_Day2Example,Test3) {
    string x{"2-9 c: ccccccccc"};
    EXPECT_TRUE(isPasswordValid(x));
}

TEST(Y2020_Day2Example,Test4) {
    string x{"1-3 a: abcde"};
    EXPECT_TRUE(isPasswordValid2(x));
}

TEST(Y2020_Day2Example,Test5) {
    string x{"1-3 b: cdefg"};
    EXPECT_FALSE(isPasswordValid2(x));
}

TEST(Y2020_Day2Example,Test6) {
    string x{"2-9 c: ccccccccc"};
    EXPECT_FALSE(isPasswordValid2(x));
}
