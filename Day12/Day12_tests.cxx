//
//  Advent of Code 2020 Tests: Day 12
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/12/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day12.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay12{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay12;

TEST(Y2020_SolveDay12, FinalSolutionPartA) {
    EXPECT_EQ("1589", solvea());
}

TEST(Y2020_SolveDay12, FinalSolutionPartB) {
    EXPECT_EQ("23960", solveb());
}

TEST(Y2020_Day12Example,Test1) {
    vector<string> input {
        "F10",
        "N3",
        "F7",
        "R90",
        "F11"
    };
    auto x = navigatePath(input);
    EXPECT_EQ(25,x);
}

TEST(Y2020_Day12Example,Test2) {
    vector<string> input {
        "F10",
        "N3",
        "F7",
        "R90",
        "F11"
    };
    auto x = navigatePath2(input);
    EXPECT_EQ(286,x);
}
