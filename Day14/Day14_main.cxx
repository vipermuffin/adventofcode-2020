//
//  Advent of Code 2020 Main Runner: Day 14
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/13/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay14{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day14" << "a: " << AocDay14::solvea() << std::endl;
    std::cout << "Day14" << "b: " << AocDay14::solveb() << std::endl;
    return 0;
}
