//
//  Advent of Code 2020 Main Runner: Day 16
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/15/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay16{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day16" << "a: " << AocDay16::solvea() << std::endl;
    std::cout << "Day16" << "b: " << AocDay16::solveb() << std::endl;
    return 0;
}
