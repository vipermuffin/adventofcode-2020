//
//  Advent of Code 2020 Solutions: Day 8
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/07/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day08.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
#include <functional> //std::function
//#include <iomanip> //setfill setw hex
//#include <map>
//#include <math.h> //sqrt
//#include <numeric> //std::accumulate
//#include <queue>
//#include <regex>
//#include <set>
//#include <sstream>
//#include <thread>
//#include <tuple>
#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay08 {
    int runProgram(const std::vector<string>& program, bool& exit);
    static const std::string InputFileName = "Day08.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        bool exit = false;
        
		return to_string(runProgram(input, exit));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        bool exit = false;
        auto nextNop = input.begin();
        while(nextNop != input.end() && nextNop->find("jmp") == string::npos) {
            nextNop++;
        }
        int x = 0;
        while(!exit && nextNop != input.end()) {
            (*nextNop)[0] = 'n';
            (*nextNop)[1] = 'o';
            x = runProgram(input, exit);
            if(!exit) {
                (*nextNop)[0] = 'j';
                (*nextNop)[1] = 'm';
                nextNop++;
                while(nextNop != input.end() && nextNop->find("jmp") == string::npos) {
                    nextNop++;
                }
            }
        }
        return exit ? to_string(x) : "---";
    }
    
    int runProgram(const std::vector<string>& program, bool& exit) {
        int count = 0;
        int pc = 0;
        unordered_map<string,function<void(int)>> ops{
            {"nop",[&](int){pc++;}},
            {"acc",[&](int x){count+=x;pc++;}},
            {"jmp",[&](int x){pc+=x;}}
        };
        unordered_map<int,int> pcVisited{};
        while(pcVisited[pc]++ == 0 && pc < program.size()) {
            auto vals = parseLineForWords(program[pc]);
            auto i = stoi(vals[1]);
            ops[vals[0]](i);
        }
        exit = pc >= program.size();
        return count;
    }

}
