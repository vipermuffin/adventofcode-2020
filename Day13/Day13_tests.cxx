//
//  Advent of Code 2020 Tests: Day 13
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/12/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day13.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay13{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay13;

TEST(Y2020_SolveDay13, FinalSolutionPartA) {
    EXPECT_EQ("222", solvea());
}

TEST(Y2020_SolveDay13, FinalSolutionPartB) {
    EXPECT_EQ("408270049879073", solveb());
}

TEST(Y2020_Day13Example,Test1) {
    int x = findEarliestBus("7,13,x,x,59,x,31,19", 939);
    EXPECT_EQ(295,x);
}

TEST(Y2020_Day13Example,Test2) {
    auto x = findEarliestTimestamp("7,13,x,x,59,x,31,19");
    EXPECT_EQ(1068781,x);
}

TEST(Y2020_Day13Example,Test3) {
    auto x = findEarliestTimestamp("17,x,13,19");
    EXPECT_EQ(3417,x);
}

TEST(Y2020_Day13Example,Test4) {
    auto x = findEarliestTimestamp("67,7,59,61");
    EXPECT_EQ(754018,x);
}

TEST(Y2020_Day13Example,Test5) {
    auto x = findEarliestTimestamp("67,x,7,59,61");
    EXPECT_EQ(779210,x);
}

TEST(Y2020_Day13Example,Test6) {
    auto x = findEarliestTimestamp("67,7,x,59,61");
    EXPECT_EQ(1261476,x);
}

TEST(Y2020_Day13Example,Test7) {
    auto x = findEarliestTimestamp("1789,37,47,1889");
    EXPECT_EQ(1202161486,x);
}
