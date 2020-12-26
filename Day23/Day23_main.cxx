//
//  Advent of Code 2020 Main Runner: Day 23
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/22/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay23{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day23" << "a: " << AocDay23::solvea() << std::endl;
    std::cout << "Day23" << "b: " << AocDay23::solveb() << std::endl;
    return 0;
}
