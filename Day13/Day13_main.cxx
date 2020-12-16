//
//  Advent of Code 2020 Main Runner: Day 13
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/12/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay13{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day13" << "a: " << AocDay13::solvea() << std::endl;
    std::cout << "Day13" << "b: " << AocDay13::solveb() << std::endl;
    return 0;
}
