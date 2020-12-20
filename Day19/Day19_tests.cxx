//
//  Advent of Code 2020 Tests: Day 19
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/18/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day19.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include "AoCUtils.h"
namespace AocDay19{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay19;

TEST(Y2020_SolveDay19, FinalSolutionPartA) {
    EXPECT_EQ("233", solvea());
}

TEST(Y2020_SolveDay19, FinalSolutionPartB) {
//    EXPECT_EQ("---", solveb());
}

TEST(Y2020_Day19Example,Test1) {
    vector<string> input {
        "0: 1 2",
        "1: \"a\"",
        "2: 1 3 | 3 1",
        "3: \"b\""
    };
    RuleBook rb = ruleBuilder(input);
    ASSERT_EQ(4,rb.size());
    EXPECT_EQ("a", rb[1].front());
    EXPECT_EQ("b", rb[3].front());
    EXPECT_EQ("ab", rb[2].front());
    EXPECT_EQ("ba", rb[2].back());
    EXPECT_EQ("aab", rb[0].front());
    EXPECT_EQ("aba", rb[0].back());
}

TEST(Y2020_Day19Example,Test2) {
    string r{"0: 1 2"};
    RuleBook rb{};
    tempRuleBook trb{};
    readRule(r, rb, trb);
    EXPECT_EQ(0,rb.size());
    EXPECT_EQ(1,trb.size());
    EXPECT_EQ(1, trb[0].front().first);
    EXPECT_EQ(2, trb[0].front().second);
}

TEST(Y2020_Day19Example,Test3) {
    string r{"1: \"a\""};
    RuleBook rb{};
    tempRuleBook trb{};
    readRule(r, rb, trb);
    EXPECT_EQ(1,rb.size());
    EXPECT_EQ("a",rb[1].front());
    EXPECT_EQ(0,trb.size());
}

TEST(Y2020_Day19Example,Test4) {
    vector<string> input {
        "0: 4 1",
        "1: 2 3 | 3 2",
        "2: 4 4 | 5 5",
        "3: 4 5 | 5 4",
        "4: \"a\"",
        "5: \"b\""
    };
    RuleBook rb = ruleBuilder(input);
    ASSERT_EQ(6,rb.size());
    EXPECT_EQ("a", rb[4].front());
    EXPECT_EQ("b", rb[5].front());
    EXPECT_EQ("ab", rb[3].front());
    EXPECT_EQ("ba", rb[3].back());
    EXPECT_EQ("aa", rb[2].front());
    EXPECT_EQ("bb", rb[2].back());
    EXPECT_EQ("aaab", rb[1].front());
    EXPECT_EQ("babb", rb[1].back());
    EXPECT_EQ(8,rb[1].size());
    EXPECT_EQ(8,rb[0].size());
}

TEST(Y2020_Day19Example,Test5) {
    vector<string> input {
        "0: 4 1 5",
        "1: 2 3 | 3 2",
        "2: 4 4 | 5 5",
        "3: 4 5 | 5 4",
        "4: \"a\"",
        "5: \"b\""
    };
    RuleBook rb = ruleBuilder(input);
    printVector(rb[0]);
    ASSERT_EQ(8,rb[0].size());
    EXPECT_EQ("aaaabb", rb[0][0]);
    EXPECT_EQ("aaabab", rb[0][1]);
    EXPECT_EQ("abbabb", rb[0][2]);
    EXPECT_EQ("abbbab", rb[0][3]);
    EXPECT_EQ("aabaab", rb[0][4]);
    EXPECT_EQ("aabbbb", rb[0][5]);
    EXPECT_EQ("abaaab", rb[0][6]);
    EXPECT_EQ("ababbb", rb[0][7]);
}
