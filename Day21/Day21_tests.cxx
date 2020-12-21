//
//  Advent of Code 2020 Tests: Day 21
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/20/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day21.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay21{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay21;

TEST(Y2020_SolveDay21, FinalSolutionPartA) {
    EXPECT_EQ("2798", solvea());
}

TEST(Y2020_SolveDay21, FinalSolutionPartB) {
    EXPECT_EQ("gbt,rpj,vdxb,dtb,bqmhk,vqzbq,zqjm,nhjrzzj", solveb());
}

TEST(Y2020_Day21Example,Test1) {
    vector<string> input {
        "mxmxvkd kfcds sqjhc nhms (contains dairy, fish)",
        "trh fvjkl sbzzf mxmxvkd (contains dairy)",
        "sqjhc fvjkl (contains soy)",
        "sqjhc mxmxvkd sbzzf (contains fish)"
    };
    unordered_map<string, vector<string>> db{};
    parseFoodRow(input[0],db);
    ASSERT_EQ(2,db.size());
    EXPECT_EQ("mxmxvkd kfcds sqjhc nhms",db.at("dairy").front());
    EXPECT_EQ("mxmxvkd kfcds sqjhc nhms",db.at("fish").front());
}

TEST(Y2020_Day21Example,Test2) {
    vector<string> input {
        "mxmxvkd kfcds sqjhc nhms (contains dairy, fish)",
        "trh fvjkl sbzzf mxmxvkd (contains dairy)",
        "sqjhc fvjkl (contains soy)",
        "sqjhc mxmxvkd sbzzf (contains fish)"
    };
    unordered_map<string, vector<string>> db = parseFoodList(input);
    ASSERT_EQ(3,db.size());
    EXPECT_EQ("mxmxvkd kfcds sqjhc nhms",db.at("dairy").front());
    EXPECT_EQ("trh fvjkl sbzzf mxmxvkd",db.at("dairy").back());
    EXPECT_EQ("mxmxvkd kfcds sqjhc nhms",db.at("fish").front());
    EXPECT_EQ("sqjhc mxmxvkd sbzzf",db.at("fish").back());
    EXPECT_EQ("sqjhc fvjkl",db.at("soy").front());
}

TEST(Y2020_Day21Example,Test3) {
    vector<string> input {
        "mxmxvkd kfcds sqjhc nhms (contains dairy, fish)",
        "trh fvjkl sbzzf mxmxvkd (contains dairy)",
        "sqjhc fvjkl (contains soy)",
        "sqjhc mxmxvkd sbzzf (contains fish)"
    };
    unordered_map<string, vector<string>> db = parseFoodList(input);
    ASSERT_EQ(3,db.size());
    auto fpl = determineFoodName(db);
    ASSERT_EQ(3,fpl.size());
    EXPECT_EQ("dairy",fpl[0].first);
    EXPECT_EQ("mxmxvkd",fpl[0].second);
    EXPECT_EQ("fish",fpl[1].first);
    EXPECT_EQ("sqjhc",fpl[1].second);
    EXPECT_EQ("soy",fpl[2].first);
    EXPECT_EQ("fvjkl",fpl[2].second);
}

TEST(Y2020_Day21Example,Test4) {
    vector<string> input {
        "mxmxvkd kfcds sqjhc nhms (contains dairy, fish)",
        "trh fvjkl sbzzf mxmxvkd (contains dairy)",
        "sqjhc fvjkl (contains soy)",
        "sqjhc mxmxvkd sbzzf (contains fish)"
    };
    
    EXPECT_EQ(5, countNonAllergens(input));
}

TEST(Y2020_Day21Example,Test5) {
    vector<string> input {
        "mxmxvkd kfcds sqjhc nhms (contains dairy, fish)",
        "trh fvjkl sbzzf mxmxvkd (contains dairy)",
        "sqjhc fvjkl (contains soy)",
        "sqjhc mxmxvkd sbzzf (contains fish)"
    };
    produceCanonicalDangerousList(input);
    EXPECT_EQ(5, countNonAllergens(input));
}
