//
//  Advent of Code 2020 Tests: Day 7
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/06/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day07.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include "AoCUtils.h"
namespace AocDay07{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay07;

TEST(Y2020_SolveDay7, FinalSolutionPartA) {
    EXPECT_EQ("205", solvea());
}

TEST(Y2020_SolveDay7, FinalSolutionPartB) {
    EXPECT_EQ("80902", solveb());
}

TEST(Y2020_Day7Example,Test1) {
    BagDictionary idb{};
    BagDictionary odb{};
    string x{"light red bags contain 1 bright white bag, 2 muted yellow bags."};
    
    updateBagDatabase(x,idb,odb);
    EXPECT_EQ(1,idb.size());
    EXPECT_EQ(2,odb.size());
}

TEST(Y2020_Day7Example,Test2) {
    vector<string> input{
        "light red bags contain 1 bright white bag, 2 muted yellow bags.",
        "dark orange bags contain 3 bright white bags, 4 muted yellow bags.",
        "bright white bags contain 1 shiny gold bag.",
        "muted yellow bags contain 2 shiny gold bags, 9 faded blue bags.",
        "shiny gold bags contain 1 dark olive bag, 2 vibrant plum bags.",
        "dark olive bags contain 3 faded blue bags, 4 dotted black bags.",
        "vibrant plum bags contain 5 faded blue bags, 6 dotted black bags.",
        "faded blue bags contain no other bags.",
        "dotted black bags contain no other bags."
    };
    BagDictionary idb{};
    BagDictionary odb{};
    for(const auto& line : input) {
        updateBagDatabase(line, idb, odb);
    }
    unordered_set<string> list{};
    findContainingBags(odb, list, "shiny gold");
    auto x = list.size();
    EXPECT_EQ(4,x);
}

TEST(Y2020_Day7Example,Test3) {
    vector<string> input{
        "light red bags contain 1 bright white bag, 2 muted yellow bags.",
        "dark orange bags contain 3 bright white bags, 4 muted yellow bags.",
        "bright white bags contain 1 shiny gold bag.",
        "muted yellow bags contain 2 shiny gold bags, 9 faded blue bags.",
        "shiny gold bags contain 1 dark olive bag, 2 vibrant plum bags.",
        "dark olive bags contain 3 faded blue bags, 4 dotted black bags.",
        "vibrant plum bags contain 5 faded blue bags, 6 dotted black bags.",
        "faded blue bags contain no other bags.",
        "dotted black bags contain no other bags."
    };
    BagDictionary idb{};
    BagDictionary odb{};
    for(const auto& line : input) {
        updateBagDatabase(line, idb, odb);
    }
    
    auto x = findNestedBags(idb, "shiny gold");
    EXPECT_EQ(32,x);
}

TEST(Y2020_Day7Example,Test4) {
    vector<string> input{
        "shiny gold bags contain 2 dark red bags.",
        "dark red bags contain 2 dark orange bags.",
        "dark orange bags contain 2 dark yellow bags.",
        "dark yellow bags contain 2 dark green bags.",
        "dark green bags contain 2 dark blue bags.",
        "dark blue bags contain 2 dark violet bags.",
        "dark violet bags contain no other bags."
    };
    BagDictionary idb{};
    BagDictionary odb{};
    for(const auto& line : input) {
        updateBagDatabase(line, idb, odb);
    }
    
    auto x = findNestedBags(idb, "shiny gold");
    EXPECT_EQ(126,x);
}
