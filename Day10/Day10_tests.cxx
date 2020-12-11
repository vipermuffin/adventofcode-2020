//
//  Advent of Code 2020 Tests: Day 10
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/09/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day10.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay10{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay10;

TEST(Y2020_SolveDay10, FinalSolutionPartA) {
    EXPECT_EQ("1890", solvea());
}

TEST(Y2020_SolveDay10, FinalSolutionPartB) {
    EXPECT_EQ("49607173328384", solveb());
}

TEST(Y2020_Day10Example,Test1) {
    vector<int> input {
        16,
        10,
        15,
        5,
        1,
        11,
        7,
        19,
        6,
        12,
        4
    };

    EXPECT_EQ(8,findAllCombos(input));
}

TEST(Y2020_Day10Example,Test2) {
    vector<int> input {
        28,
        33,
        18,
        42,
        31,
        14,
        46,
        20,
        48,
        47,
        24,
        23,
        49,
        45,
        19,
        38,
        39,
        11,
        1,
        32,
        25,
        35,
        8,
        17,
        7,
        9,
        4,
        2,
        34,
        10,
        3
    };
    EXPECT_EQ(19208,findAllCombos(input));
}

