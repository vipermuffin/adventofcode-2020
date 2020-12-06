//
//  Advent of Code 2020 Tests: Day 6
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/05/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day06.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay06{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay06;

TEST(Y2020_SolveDay6, FinalSolutionPartA) {
    EXPECT_EQ("7120", solvea());
}

TEST(Y2020_SolveDay6, FinalSolutionPartB) {
    EXPECT_EQ("3570", solveb());
}

TEST(Y2020_Day6Example,Test1) {
    vector<string> g{
        "abc",
        "",
        "a",
        "b",
        "c",
        "",
        "ab",
        "ac",
        "",
        "a",
        "a",
        "a",
        "a",
        "",
        "b"
    };
    auto x = buildGroupStrings(g);
    ASSERT_EQ(5,x.size());
    EXPECT_EQ("abc",x[0]);
    EXPECT_EQ("a,b,c",x[1]);
    EXPECT_EQ("ab,ac",x[2]);
    EXPECT_EQ("a,a,a,a",x[3]);
    EXPECT_EQ("b",x[4]);
}

TEST(Y2020_Day6Example,Test2) {
    vector<string> g{
        "abc",
        "",
        "a",
        "b",
        "c",
        "",
        "ab",
        "ac",
        "",
        "a",
        "a",
        "a",
        "a",
        "",
        "b"
    };
    auto x = buildGroupStrings(g);
    EXPECT_EQ(11,countAnyYesPerGroup(x));
}

TEST(Y2020_Day6Example,Test3) {
    vector<string> g{
        "abc",
        "",
        "a",
        "b",
        "c",
        "",
        "ab",
        "ac",
        "",
        "a",
        "a",
        "a",
        "a",
        "",
        "b"
    };
    auto x = buildGroupStrings(g);
    EXPECT_EQ(6,countAllYesPerGroup(x));
}
