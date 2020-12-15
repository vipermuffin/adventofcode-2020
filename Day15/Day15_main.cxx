//
//  Advent of Code 2020 Main Runner: Day 15
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/14/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay15{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day15" << "a: " << AocDay15::solvea() << std::endl;
    std::cout << "Day15" << "b: " << AocDay15::solveb() << std::endl;
    return 0;
}
