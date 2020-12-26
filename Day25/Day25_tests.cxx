//
//  Advent of Code 2020 Tests: Day 25
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/26/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day25.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay25{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay25;

TEST(Y2020_SolveDay25, FinalSolutionPartA) {
    EXPECT_EQ("9177528", solvea());
}

TEST(Y2020_SolveDay25, FinalSolutionPartB) {
    EXPECT_EQ("---", solveb());
}

TEST(Y2020_Day25Example,Test1) {
    EXPECT_EQ(8,findLoopSize(5764801));
    EXPECT_EQ(11,findLoopSize(17807724));
}

TEST(Y2020_Day25Example,Test2) {
    EXPECT_EQ(14897079,findSecretKey(17807724, 8));
    EXPECT_EQ(14897079,findSecretKey(5764801, 11));
}

TEST(Y2020_Day25Example,Test3) {
    int x = 0;
    EXPECT_EQ(0,x);
}
