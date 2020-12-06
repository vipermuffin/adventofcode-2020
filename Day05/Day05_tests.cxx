//
//  Advent of Code 2020 Tests: Day 5
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/04/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day05.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay05{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay05;

TEST(Y2020_SolveDay5, FinalSolutionPartA) {
    EXPECT_EQ("919", solvea());
}

TEST(Y2020_SolveDay5, FinalSolutionPartB) {
    EXPECT_EQ("642", solveb());
}

TEST(Y2020_Day5Example,Test1) {
    auto x = getSeatId("FBFBBFFRLR");
    EXPECT_EQ(44*8+5,x);
}

TEST(Y2020_Day5Example,Test2) {
    auto x = getSeatId("BFFFBBFRRR");
    EXPECT_EQ(567,x);
}

TEST(Y2020_Day5Example,Test3) {
    auto x = getSeatId("FFFBBBFRRR");
    EXPECT_EQ(119,x);
}

TEST(Y2020_Day5Example,Test4) {
    auto x = getSeatId("BBFFBBFRLL");
    EXPECT_EQ(820,x);
}
