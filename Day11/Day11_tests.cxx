//
//  Advent of Code 2020 Tests: Day 11
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/10/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day11.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <unordered_map>
namespace AocDay11{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay11;

TEST(Y2020_SolveDay11, FinalSolutionPartA) {
    EXPECT_EQ("2108", solvea());
}

TEST(Y2020_SolveDay11, FinalSolutionPartB) {
    EXPECT_EQ("1897", solveb());
}

TEST(Y2020_Day11Example,Test1a) {
    vector<string> map {
        "L.LL.LL.LL",
        "LLLLLLL.LL",
        "L.L.L..L..",
        "LLLL.LL.LL",
        "L.LL.LL.LL",
        "L.LLLLL.LL",
        "..L.L.....",
        "LLLLLLLLLL",
        "L.LLLLLL.L",
        "L.LLLLL.LL"
    };
    vector<string> result {
"#.##.##.##",
"#######.##",
"#.#.#..#..",
"####.##.##",
"#.##.##.##",
"#.#####.##",
        "..#.#.....",
"##########",
"#.######.#",
"#.#####.##"
    };
    performSeating(map);
    for(int i = 0; i < map.size();i++) {
        EXPECT_EQ(result[i], map[i]);
    }
}

TEST(Y2020_Day11Example,Test1b) {
    vector<string> result {
"#.LL.L#.##",
"#LLLLLL.L#",
        "L.L.L..L..",
"#LLL.LL.L#",
"#.LL.LL.LL",
"#.LLLL#.##",
        "..L.L.....",
"#LLLLLLLL#",
"#.LLLLLL.L",
"#.#LLLL.##"
    };
    vector<string> map {
        "#.##.##.##",
        "#######.##",
        "#.#.#..#..",
        "####.##.##",
        "#.##.##.##",
        "#.#####.##",
        "..#.#.....",
        "##########",
        "#.######.#",
        "#.#####.##"
    };
    performSeating(map);
    for(int i = 0; i < map.size();i++) {
//        cout << i;
        EXPECT_EQ(result[i], map[i]);
    }
}

TEST(Y2020_Day11Example,Test2a) {
    vector<string> input {
        "L.LL.LL.LL",
        "LLLLLLL.LL",
        "L.L.L..L..",
        "LLLL.LL.LL",
        "L.LL.LL.LL",
        "L.LLLLL.LL",
        "..L.L.....",
        "LLLLLLLLLL",
        "L.LLLLLL.L",
        "L.LLLLL.LL"
    };
    unordered_map<string, int32_t> arrangements{};
    auto s = convertMapToString(input);
    auto previousS{s};
    arrangements[s]++;
    do {
        std::swap(s,previousS);
        performSeating(input);
        s = convertMapToString(input);
    }while(s!=previousS);
    auto x = std::count(s.begin(),s.end(),'#');
    EXPECT_EQ(37,x);
}

TEST(Y2020_Day11Example,Test2b) {
    vector<string> input {
        "L.LL.LL.LL",
        "LLLLLLL.LL",
        "L.L.L..L..",
        "LLLL.LL.LL",
        "L.LL.LL.LL",
        "L.LLLLL.LL",
        "..L.L.....",
        "LLLLLLLLLL",
        "L.LLLLLL.L",
        "L.LLLLL.LL"
    };
    auto s = convertMapToString(input);
    auto previousS{s};
    do {
        std::swap(s,previousS);
        performSeating2(input);
        s = convertMapToString(input);
    }while(s!=previousS);
    auto x = std::count(s.begin(),s.end(),'#');
    EXPECT_EQ(26,x);
}

TEST(Y2020_Day11Example,Test3) {
    vector<string> map {
        "#.##.##.##",
        "#######.##",
        "#.#.#..#.."
    };
    auto x = convertMapToString(map);
    EXPECT_EQ("#.##.##.#########.###.#.#..#..",x);
}

TEST(Y2020_Day11Example,Test4) {
    vector<string> map {
        ".##.##.",
        "#.#.#.#",
        "##...##",
        "...L...",
        "##...##",
        "#.#.#.#",
        ".##.##."
    };
    auto s = convertMapToString(map);
    EXPECT_EQ(0,adjacentOccupiedRowCount(s,3,3,map.front().size()));
}

TEST(Y2020_Day11Example,Test5) {
    vector<string> map {
        ".......#.",
        "...#.....",
        ".#.......",
        ".........",
        "..#L....#",
        "....#....",
        ".........",
        "#........",
        "...#....."
    };
    auto s = convertMapToString(map);
    EXPECT_EQ(8,adjacentOccupiedRowCount(s,4,3,map.front().size()));
}

TEST(Y2020_Day11Example,Test6) {
    vector<string> map {
        ".............",
        ".L.L.#.#.#.#.",
        "............."
    };
    auto s = convertMapToString(map);
    EXPECT_EQ(0,adjacentOccupiedRowCount(s,1,1,map.front().size()));
}

TEST(Y2020_Day11Example,Test7) {
    vector<string> result {
       "#.LL.LL.L#",
       "#LLLLLL.LL",
       "L.L.L..L..",
       "LLLL.LL.LL",
       "L.LL.LL.LL",
       "L.LLLLL.LL",
       "..L.L.....",
       "LLLLLLLLL#",
       "#.LLLLLL.L",
       "#.LLLLL.L#"
    };
    vector<string> map {
        "#.##.##.##",
        "#######.##",
        "#.#.#..#..",
        "####.##.##",
        "#.##.##.##",
        "#.#####.##",
        "..#.#.....",
        "##########",
        "#.######.#",
        "#.#####.##"
    };
    performSeating2(map);
    for(int i = 0; i < map.size();i++) {
//        cout << i;
        EXPECT_EQ(result[i], map[i]);
    }
}
