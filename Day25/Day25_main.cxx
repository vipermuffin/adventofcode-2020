//
//  Advent of Code 2020 Main Runner: Day 25
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/26/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#include <stdio.h>
#include <string>
#include <iostream>

namespace AocDay25{
    extern std::string solvea();
    extern std::string solveb();
}
using namespace std;

int main(int argc, char *argv[]) {

    std::cout << "Day25" << "a: " << AocDay25::solvea() << std::endl;
    std::cout << "Day25" << "b: " << AocDay25::solveb() << std::endl;
    return 0;
}
