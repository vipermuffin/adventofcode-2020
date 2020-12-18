//
//  Advent of Code 2020 Tests: Day 18
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/17/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day18.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay18{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay18;

TEST(Y2020_SolveDay18, FinalSolutionPartA) {
    EXPECT_EQ("4940631886147", solvea());
}

TEST(Y2020_SolveDay18, FinalSolutionPartB) {
    EXPECT_EQ("283582817678281", solveb());
}

TEST(Y2020_Day18Example,Test1) {
    EXPECT_EQ(26,evaluateExpression("2 * 3 + (4 * 5)"));
    EXPECT_EQ(437,evaluateExpression("5 + (8 * 3 + 9 + 3 * 4 * 3)"));
    EXPECT_EQ(12240,evaluateExpression("5 * 9 * (7 * 3 * 3 + 9 * 3 + (8 + 6 * 4))"));
    EXPECT_EQ(13632,evaluateExpression("((2 + 4 * 9) * (6 + 9 * 8 + 6) + 6) + 2 + 4 * 2"));
}

TEST(Y2020_Day18Example,Test2) {
    EXPECT_EQ(51,evaluateAdvExpression("1 + (2 * 3) + (4 * (5 + 6))"));
    EXPECT_EQ(46,evaluateAdvExpression("2 * 3 + (4 * 5)"));
    EXPECT_EQ(1445,evaluateAdvExpression("5 + (8 * 3 + 9 + 3 * 4 * 3)"));
    EXPECT_EQ(669060,evaluateAdvExpression("5 * 9 * (7 * 3 * 3 + 9 * 3 + (8 + 6 * 4))"));
    EXPECT_EQ(23340,evaluateAdvExpression("((2 + 4 * 9) * (6 + 9 * 8 + 6) + 6) + 2 + 4 * 2"));
}

