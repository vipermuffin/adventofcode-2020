//
//  Advent of Code 2020 Tests: Day 9
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/08/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day09.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay09{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay09;

TEST(Y2020_SolveDay9, FinalSolutionPartA) {
    EXPECT_EQ("26134589", solvea());
}

TEST(Y2020_SolveDay9, FinalSolutionPartB) {
    EXPECT_EQ("3535124", solveb());
}

TEST(Y2020_Day9Example,Test1a) {
    vector<int64_t> vals {
        35,
        20,
        15,
        25,
        47
    };
    EXPECT_TRUE(isValid(vals, 40));
}

TEST(Y2020_Day9Example,Test1b) {
    vector<int64_t> vals {
        95,
        102,
        117,
        150,
        182,
    };
    EXPECT_FALSE(isValid(vals, 127));
}

TEST(Y2020_Day9Example,Test2) {
    vector<int64_t> vals {
        35,
        20,
        15,
        25,
        47,
        40,
        62,
        55,
        65,
        95,
        102,
        117,
        150,
        182,
        127,
        219,
        299,
        277,
        309,
        576
    };
    EXPECT_EQ(127,findInvalidVal(vals, 5));
}

TEST(Y2020_Day9Example,Test3) {
    vector<int64_t> vals {
        35,
        20,
        15,
        25,
        47,
        40,
        62,
        55,
        65,
        95,
        102,
        117,
        150,
        182,
        127,
        219,
        299,
        277,
        309,
        576
    };
    EXPECT_EQ(62,findInvalidValMatch(vals, 127));
}
