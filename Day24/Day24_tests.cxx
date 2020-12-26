//
//  Advent of Code 2020 Tests: Day 24
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/26/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day24.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay24{
    extern std::string solvea();
    extern std::string solveb();
}

using namespace std;
using namespace AocDay24;

TEST(Y2020_SolveDay24, FinalSolutionPartA) {
    EXPECT_EQ("230", solvea());
}

TEST(Y2020_SolveDay24, FinalSolutionPartB) {
    EXPECT_EQ("3565", solveb());
}

TEST(Y2020_Day24Example,Test1) {
    string line{"sesenwnenenewseeswwswswwnenewsewsw"};
    auto x = parseDirections(line);
    EXPECT_EQ(20,x.size());
    EXPECT_EQ("se",x.front());
    EXPECT_EQ("sw",x.back());
}

TEST(Y2020_Day24Example,Test2) {
    vector<string> input {
        "sesenwnenenewseeswwswswwnenewsewsw",
        "neeenesenwnwwswnenewnwwsewnenwseswesw",
        "seswneswswsenwwnwse",
        "nwnwneseeswswnenewneswwnewseswneseene",
        "swweswneswnenwsewnwneneseenw",
        "eesenwseswswnenwswnwnwsewwnwsene",
        "sewnenenenesenwsewnenwwwse",
        "wenwwweseeeweswwwnwwe",
        "wsweesenenewnwwnwsenewsenwwsesesenwne",
        "neeswseenwwswnwswswnw",
        "nenwswwsewswnenenewsenwsenwnesesenew",
        "enewnwewneswsewnwswenweswnenwsenwsw",
        "sweneswneswneneenwnewenewwneswswnese",
        "swwesenesewenwneswnwwneseswwne",
        "enesenwswwswneneswsenwnewswseenwsese",
        "wnwnesenesenenwwnenwsewesewsesesew",
        "nenewswnwewswnenesenwnesewesw",
        "eneswnwswnwsenenwnwnwwseeswneewsenese",
        "neswnwewnwnwseenwseesewsenwsweewe",
        "wseweeenwnesenwwwswnew"
    };
    EXPECT_EQ(10,flipTiles(input));
}

TEST(Y2020_Day24Example,Test3) {
    vector<string> input {
        "sesenwnenenewseeswwswswwnenewsewsw",
        "neeenesenwnwwswnenewnwwsewnenwseswesw",
        "seswneswswsenwwnwse",
        "nwnwneseeswswnenewneswwnewseswneseene",
        "swweswneswnenwsewnwneneseenw",
        "eesenwseswswnenwswnwnwsewwnwsene",
        "sewnenenenesenwsewnenwwwse",
        "wenwwweseeeweswwwnwwe",
        "wsweesenenewnwwnwsenewsenwwsesesenwne",
        "neeswseenwwswnwswswnw",
        "nenwswwsewswnenenewsenwsenwnesesenew",
        "enewnwewneswsewnwswenweswnenwsenwsw",
        "sweneswneswneneenwnewenewwneswswnese",
        "swwesenesewenwneswnwwneseswwne",
        "enesenwswwswneneswsenwnewswseenwsese",
        "wnwnesenesenenwwnenwsewesewsesesew",
        "nenewswnwewswnenesenwnesewesw",
        "eneswnwswnwsenenwnwnwwseeswneewsenese",
        "neswnwewnwnwseenwseesewsenwsweewe",
        "wseweeenwnesenwwwswnew"
    };
    EXPECT_EQ(15,flipTilesWaitXDays(input, 1));
    EXPECT_EQ(12,flipTilesWaitXDays(input, 2));
    EXPECT_EQ(25,flipTilesWaitXDays(input, 3));
    EXPECT_EQ(2208,flipTilesWaitXDays(input, 100));
}
