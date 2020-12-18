//
//  Advent of Code 2020 Tests: Day 17
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/17/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day17.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay17{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay17;

TEST(Y2020_SolveDay17, FinalSolutionPartA) {
    EXPECT_EQ("257", solvea());
}

TEST(Y2020_SolveDay17, FinalSolutionPartB) {
    EXPECT_EQ("2532", solveb());
}

TEST(Y2020_Day17Example,Test1) {
    vector<string> initState {
        ".#.",
        "..#",
        "###"
    };
    PointInfo tmp;
    auto x = initMap(initState);
    ASSERT_EQ(5,x.size());
    tmp.all = 0;
    tmp.val[X] = 1;
    EXPECT_TRUE(x[tmp.all]);
    tmp.val[X] = 2;
    tmp.val[Y] = 1;
    EXPECT_TRUE(x[tmp.all]);
    tmp.val[Y] = 2;
    EXPECT_TRUE(x[tmp.all]);
    tmp.val[X]=1;
    EXPECT_TRUE(x[tmp.all]);
    tmp.val[X]=0;
    EXPECT_TRUE(x[tmp.all]);
}

TEST(Y2020_Day17Example,Test2) {
    vector<string> initState {
        ".#.",
        "..#",
        "###"
    };

    auto x = initMap(initState);
    auto ret = performCycle(x);
    EXPECT_EQ(11,ret);
    ret = performCycle(x);
    EXPECT_EQ(21,ret);
    ret = performCycle(x);
    EXPECT_EQ(38,ret);
    ret = performCycle(x);
    ret = performCycle(x);
    ret = performCycle(x);
    EXPECT_EQ(112,ret);
}

TEST(Y2020_Day17Example,Test3) {
    vector<string> initState {
        ".#.",
        "..#",
        "###"
    };
    
    auto x = initMap(initState);
    auto ret = performCycle(x,true);
    EXPECT_EQ(29,ret);
    ret = performCycle(x,true);
    ret = performCycle(x,true);
    ret = performCycle(x,true);
    ret = performCycle(x,true);
    ret = performCycle(x,true);
    EXPECT_EQ(848,ret);
}
