//
//  Advent of Code 2020 Tests: Day 8
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/07/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day08.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay08{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay08;

TEST(Y2020_SolveDay8, FinalSolutionPartA) {
    EXPECT_EQ("1930", solvea());
}

TEST(Y2020_SolveDay8, FinalSolutionPartB) {
    EXPECT_EQ("1688", solveb());
}

TEST(Y2020_Day8Example,Test1) {
    vector<string> prog {
        "nop +0",
        "acc +1",
        "jmp +4",
        "acc +3",
        "jmp -3",
        "acc -99",
        "acc +1",
        "jmp -4",
        "acc +6"
    };
    bool exited{true};
    auto x = runProgram(prog, exited);
    EXPECT_EQ(5,x);
    EXPECT_FALSE(exited);
}

TEST(Y2020_Day8Example,Test2) {
    vector<string> prog {
        "nop +0",
        "acc +1",
        "jmp +4",
        "acc +3",
        "jmp -3",
        "acc -99",
        "acc +1",
        "jmp -4",
        "acc +6"
    };
    bool exited{false};
    auto x = fixCorruptProgram(prog, exited);
    EXPECT_EQ(8,x);
    EXPECT_TRUE(exited);
}
