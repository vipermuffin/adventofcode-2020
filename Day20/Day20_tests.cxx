//
//  Advent of Code 2020 Tests: Day 20
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/20/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day20.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

namespace AocDay20{
    extern std::string solvea();
    extern std::string solveb();
    std::vector<std::string> sampleInput{
        "Tile 2311:",
        "..##.#..#.",
        "##..#.....",
        "#...##..#.",
        "####.#...#",
        "##.##.###.",
        "##...#.###",
        ".#.#.#..##",
        "..#....#..",
        "###...#.#.",
        "..###..###",
        "",
        "Tile 1951:",
        "#.##...##.",
        "#.####...#",
        ".....#..##",
        "#...######",
        ".##.#....#",
        ".###.#####",
        "###.##.##.",
        ".###....#.",
        "..#.#..#.#",
        "#...##.#..",
        "",
        "Tile 1171:",
        "####...##.",
        "#..##.#..#",
        "##.#..#.#.",
        ".###.####.",
        "..###.####",
        ".##....##.",
        ".#...####.",
        "#.##.####.",
        "####..#...",
        ".....##...",
        "",
        "Tile 1427:",
        "###.##.#..",
        ".#..#.##..",
        ".#.##.#..#",
        "#.#.#.##.#",
        "....#...##",
        "...##..##.",
        "...#.#####",
        ".#.####.#.",
        "..#..###.#",
        "..##.#..#.",
        "",
        "Tile 1489:",
        "##.#.#....",
        "..##...#..",
        ".##..##...",
        "..#...#...",
        "#####...#.",
        "#..#.#.#.#",
        "...#.#.#..",
        "##.#...##.",
        "..##.##.##",
        "###.##.#..",
        "",
        "Tile 2473:",
        "#....####.",
        "#..#.##...",
        "#.##..#...",
        "######.#.#",
        ".#...#.#.#",
        ".#########",
        ".###.#..#.",
        "########.#",
        "##...##.#.",
        "..###.#.#.",
        "",
        "Tile 2971:",
        "..#.#....#",
        "#...###...",
        "#.#.###...",
        "##.##..#..",
        ".#####..##",
        ".#..####.#",
        "#..#.#..#.",
        "..####.###",
        "..#.#.###.",
        "...#.#.#.#",
        "",
        "Tile 2729:",
        "...#.#.#.#",
        "####.#....",
        "..#.#.....",
        "....#..#.#",
        ".##..##.#.",
        ".#.####...",
        "####.#.#..",
        "##.####...",
        "##..#.##..",
        "#.##...##.",
        "",
        "Tile 3079:",
        "#.#.#####.",
        ".#..######",
        "..#.......",
        "######....",
        "####.#..#.",
        ".#...#.##.",
        "#.#####.##",
        "..#.###...",
        "..#.......",
        "..#.###..."
    };
}

using namespace std;
using namespace AocDay20;

TEST(Y2020_SolveDay20, FinalSolutionPartA) {
    EXPECT_EQ("28057939502729", solvea());
}

TEST(Y2020_SolveDay20, FinalSolutionPartB) {
    EXPECT_EQ("---", solveb());
}

TEST(Y2020_Day20Example,Test1) {
    vector<string> input1 {
        "Tile 2311:",
        "..##.#..#.",
        "##..#.....",
        "#...##..#.",
        "####.#...#",
        "##.##.###.",
        "##...#.###",
        ".#.#.#..##",
        "..#....#..",
        "###...#.#.",
        "..###..###"
    };
    ImageTile it1{input1};
    vector<string> input2 {
        "Tile 1951:",
        "#.##...##.",
        "#.####...#",
        ".....#..##",
        "#...######",
        ".##.#....#",
        ".###.#####",
        "###.##.##.",
        ".###....#.",
        "..#.#..#.#",
        "#...##.#.."
    };
    ImageTile it2{input2};
    
    EXPECT_TRUE(it1.isPossibleNeighbor(it2));
}

TEST(Y2020_Day20Example,Test2) {
    vector<string> input1 {
        "Tile 2311:",
        "..##.#..#.",
        "##..#.....",
        "#...##..#.",
        "####.#...#",
        "##.##.###.",
        "##...#.###",
        ".#.#.#..##",
        "..#....#..",
        "###...#.#.",
        "..###..###"
    };
    ImageTile it1{input1};
    vector<string> input2 {
        "Tile 1489:",
        "##.#.#....",
        "..##...#..",
        ".##..##...",
        "..#...#...",
        "#####...#.",
        "#..#.#.#.#",
        "...#.#.#..",
        "##.#...##.",
        "..##.##.##",
        "###.##.#.."
    };
    ImageTile it2{input2};
    
    EXPECT_FALSE(it1.isPossibleNeighbor(it2));
}

TEST(Y2020_Day20Example,Test3) {
    auto itv = tileFactory(sampleInput);
    ASSERT_EQ(72,itv.size());
    auto x = findFourCorners(itv);
    EXPECT_EQ(20899048083289,x);
}

TEST(Y2020_Day20Example,Test4) {
    auto itv = tileFactory(sampleInput);
    ASSERT_EQ(9,itv.size());
    auto x = findArrangement(itv);
    EXPECT_EQ(4,x.size());
}

TEST(Y2020_Day20Example,Test5) {
    vector<string> input1 {
        "Tile 2311:",
        "..##.#..#.",
        "##..#.....",
        "#...##..#.",
        "####.#...#",
        "##.##.###.",
        "##...#.###",
        ".#.#.#..##",
        "..#....#..",
        "###...#.#.",
        "..###..###"
    };
    ImageTile t{input1};
    EXPECT_EQ("2311", t.tileName);
    t.displayImage();
    cout << "---" << endl;
    t.flip();
    EXPECT_EQ("2311F",t.tileName);
    t.displayImage(true);
    cout << "---" << endl;
    t.rotateClockwise();
    t.displayImage(true);
    cout << "---" << endl;
}

