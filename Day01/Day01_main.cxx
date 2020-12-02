//
//  Advent of Code 2020 Main Runner: Day 1
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 11/30/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay01{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day01" << "a: " << AocDay01::solvea() << std::endl;
    std::cout << "Day01" << "b: " << AocDay01::solveb() << std::endl;
    return 0;
}
