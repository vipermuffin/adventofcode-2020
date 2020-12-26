//
//  Advent of Code 2020 Tests: Day 23
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/22/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day23.h"
#include "gtest/gtest.h"
#include <iostream>


namespace AocDay23{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay23;

TEST(Y2020_SolveDay23, FinalSolutionPartA) {
    EXPECT_EQ("72496583", solvea());
}

TEST(Y2020_SolveDay23, FinalSolutionPartB) {
    EXPECT_EQ("41785843847", solveb());
}

TEST(Y2020_Day23Example,Test1) {
    list<int32_t> input{3,8,9,1,2,5,4,6,7};
    auto x = playGame(input, 10);
    EXPECT_EQ("92658374",x);
}

TEST(Y2020_Day23Example,Test2) {
    list<int32_t> input{3,8,9,1,2,5,4,6,7};
    auto x = playGame(input, 100);
    EXPECT_EQ("67384529",x);
}

TEST(Y2020_Day23Example,Test3) {
    list<int32_t> input{3,8,9,1,2,5,4,6,7};
    auto x = playGame2(input, 100);
    EXPECT_EQ(6*7,x);
}

TEST(Y2020_Day23Example,Test3b) {
    list<int32_t> input{3,8,9,1,2,5,4,6,7};
    for(int i = 10; i <= 1000000; i++ ) {
        input.push_back(i);
    }

    auto x = playGame2(input, 10000000);
    EXPECT_EQ(149245887792,x);
}
