//
//  Advent of Code 2020 Tests: Day 14
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/13/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day14.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <unordered_map>

namespace AocDay14{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay14;

TEST(Y2020_SolveDay14, FinalSolutionPartA) {
    EXPECT_EQ("5902420735773", solvea());
}

TEST(Y2020_SolveDay14, FinalSolutionPartB) {
    EXPECT_EQ("3801988250775", solveb());
}

TEST(Y2020_Day14Example,Test1) {
    vector<string> prog {
        "mask = XXXXXXXXXXXXXXXXXXXXXXXXXXXXX1XXXX0X",
        "mem[8] = 11",
        "mem[7] = 101",
        "mem[8] = 0"
    };
    unordered_map<int64_t,int64_t> regs{};
    runProgram(prog, regs);
    EXPECT_EQ(101, regs[7]);
    EXPECT_EQ(64,regs[8]);
}

TEST(Y2020_Day14Example,Test2) {
    vector<string> prog {
        "mask = 000000000000000000000000000000X1001X",
        "mem[42] = 100"
    };
    unordered_map<int64_t,int64_t> regs{};
    runProgramV2(prog, regs);
    EXPECT_EQ(4,regs.size());
    EXPECT_EQ(100,regs[26]);
    EXPECT_EQ(100,regs[27]);
    EXPECT_EQ(100,regs[58]);
    EXPECT_EQ(100,regs[59]);
}

TEST(Y2020_Day14Example,Test3) {
    vector<string> prog {
        "mask = 000000000000000000000000000000X1001X",
        "mem[42] = 100",
        "mask = 00000000000000000000000000000000X0XX",
        "mem[26] = 1"
    };
    unordered_map<int64_t,int64_t> regs{};
    runProgramV2(prog, regs);
    EXPECT_EQ(10,regs.size());
    EXPECT_EQ(1,regs[16]);
    EXPECT_EQ(1,regs[17]);
    EXPECT_EQ(1,regs[18]);
    EXPECT_EQ(1,regs[19]);
    EXPECT_EQ(1,regs[24]);
    EXPECT_EQ(1,regs[25]);
    EXPECT_EQ(1,regs[26]);
    EXPECT_EQ(1,regs[27]);
    EXPECT_EQ(100,regs[58]);
    EXPECT_EQ(100,regs[59]);
}
