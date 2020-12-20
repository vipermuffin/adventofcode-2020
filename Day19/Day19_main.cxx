//
//  Advent of Code 2020 Main Runner: Day 19
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/18/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay19{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day19" << "a: " << AocDay19::solvea() << std::endl;
    std::cout << "Day19" << "b: " << AocDay19::solveb() << std::endl;
    return 0;
}
