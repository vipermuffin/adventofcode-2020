//
//  Advent of Code 2020 Tests: Day 4
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/03/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day04.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay04{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay04;

TEST(Y2020_SolveDay4, FinalSolutionPartA) {
    EXPECT_EQ("226", solvea());
}

TEST(Y2020_SolveDay4, FinalSolutionPartB) {
    EXPECT_EQ("160", solveb());
}

TEST(Y2020_Day4Example,Test1) {
    vector<string> inp{
    "ecl:gry pid:860033327 eyr:2020 hcl:#fffffd",
    "byr:1937 iyr:2017 cid:147 hgt:183cm",
        "",
    "iyr:2013 ecl:amb cid:350 eyr:2023 pid:028048884",
    "hcl:#cfa07d byr:1929"
    };
    vector<string> outp{};
    buildPassportStrings(inp, outp);
    ASSERT_EQ(2,outp.size());
    EXPECT_EQ("ecl:gry pid:860033327 eyr:2020 hcl:#fffffd byr:1937 iyr:2017 cid:147 hgt:183cm", outp[0]);
    EXPECT_EQ("iyr:2013 ecl:amb cid:350 eyr:2023 pid:028048884 hcl:#cfa07d byr:1929", outp[1]);
}

TEST(Y2020_Day4Example,Test2) {
    unordered_map<string, string> x{};
    string inp{"ecl:gry pid:860033327 eyr:2020 hcl:#fffffd byr:1937 iyr:2017 cid:147 hgt:183cm"};
    updatePassportMap(inp, x);
    EXPECT_EQ(8,x.size());
    EXPECT_EQ("gry",x["ecl"]);
}

TEST(Y2020_Day4Example,Test3) {
    string inp{"ecl:gry pid:860033327 eyr:2020 hcl:#fffffd byr:1937 iyr:2017 cid:147 hgt:183cm"};
    unordered_map<string, string> x{};
    updatePassportMap(inp, x);
    EXPECT_TRUE(passportIsValid(x));
}

TEST(Y2020_Day4Example,Test4) {
    string inp{"iyr:2013 ecl:amb cid:350 eyr:2023 pid:028048884 hcl:#cfa07d byr:1929"};
    unordered_map<string, string> x{};
    updatePassportMap(inp, x);
    EXPECT_FALSE(passportIsValid(x));
}

TEST(Y2020_Day4Example,Test5) {
    string inp{"eyr:1972 cid:100 hcl:#18171d ecl:amb hgt:170 pid:186cm iyr:2018 byr:1926"};
    unordered_map<string, string> x{};
    updatePassportMap(inp, x);
    EXPECT_FALSE(passportIsValid2(x));
}

TEST(Y2020_Day4Example,Test6) {
    string inp{"iyr:2019 hcl:#602927 eyr:1967 hgt:170cm ecl:grn pid:012533040 byr:1946"};
    unordered_map<string, string> x{};
    updatePassportMap(inp, x);
    EXPECT_FALSE(passportIsValid2(x));
}

TEST(Y2020_Day4Example,Test7) {
    string inp{"hcl:dab227 iyr:2012 ecl:brn hgt:182cm pid:021572410 eyr:2020 byr:1992 cid:277"};
    unordered_map<string, string> x{};
    updatePassportMap(inp, x);
    EXPECT_FALSE(passportIsValid2(x));
}

TEST(Y2020_Day4Example,Test8) {
    string inp{"hgt:59cm ecl:zzz eyr:2038 hcl:74454a iyr:2023 pid:3556412378 byr:2007"};
    unordered_map<string, string> x{};
    updatePassportMap(inp, x);
    EXPECT_FALSE(passportIsValid2(x));
}

TEST(Y2020_Day4Example,Test9) {
    string inp{"pid:087499704 hgt:74in ecl:grn iyr:2012 eyr:2030 byr:1980 hcl:#623a2f"};
    unordered_map<string, string> x{};
    updatePassportMap(inp, x);
    EXPECT_TRUE(passportIsValid2(x));
}

TEST(Y2020_Day4Example,Test10) {
    string inp{"eyr:2029 ecl:blu cid:129 byr:1989 iyr:2014 pid:896056539 hcl:#a97842 hgt:165cm"};
    unordered_map<string, string> x{};
    updatePassportMap(inp, x);
    EXPECT_TRUE(passportIsValid2(x));
}

TEST(Y2020_Day4Example,Test11) {
    string inp{"hcl:#888785 hgt:164cm byr:2001 iyr:2015 cid:88 pid:545766238 ecl:hzl eyr:2022"};
    unordered_map<string, string> x{};
    updatePassportMap(inp, x);
    EXPECT_TRUE(passportIsValid2(x));
}

TEST(Y2020_Day4Example,Test12) {
    string inp{"iyr:2010 hgt:158cm hcl:#b6652a ecl:blu byr:1944 eyr:2021 pid:093154719"};
    unordered_map<string, string> x{};
    updatePassportMap(inp, x);
    EXPECT_TRUE(passportIsValid2(x));
}
