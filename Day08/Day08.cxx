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
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <functional> //std::function
#include <unordered_map>



using namespace std;
namespace AocDay08 {
    
    static const std::string InputFileName = "Day08.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        bool exit = false;
		return to_string(runProgram(input, exit));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        bool didExit = false;
        auto x = fixCorruptProgram(input, didExit);
        return didExit ? to_string(x) : "---";
    }
    
    int32_t runProgram(const std::vector<string>& program, bool& exited) {
        int32_t count = 0;
        int32_t pc = 0;
        unordered_map<string,function<void(int)>> ops{
            {"nop",[&](int32_t){pc++;}},
            {"acc",[&](int32_t x){count+=x;pc++;}},
            {"jmp",[&](int32_t x){pc+=x;}}
        };
        unordered_map<int32_t,int32_t> pcVisited{};
        while(pcVisited[pc]++ == 0 && pc < program.size()) {
            auto vals = parseLineForWords(program[pc]);
            auto i = stoi(vals[1]);
            ops[vals[0]](i);
        }
        exited = pc >= program.size();
        return count;
    }
    
    int32_t fixCorruptProgram(const std::vector<std::string>&program, bool& success) {
        auto input{program};
        bool didExit = false;
        bool firstPass = false;
        string findStr{"nop"};
        string replaceStr{"jmp"};
        int x = 0;
        do {
            firstPass = !firstPass;
            auto nextNop = input.begin();
            while(nextNop != input.end() && nextNop->find(findStr) == string::npos) {
                nextNop++;
            }
            while(!didExit && nextNop != input.end()) {
                (*nextNop)[0] = replaceStr[0];(*nextNop)[1] = replaceStr[1];
                x = runProgram(input, didExit);
                if(!didExit) {
                    (*nextNop)[0] = findStr[0];(*nextNop)[1] = findStr[1];
                    while(++nextNop != input.end() && nextNop->find(findStr) == string::npos) {}
                }
            }
            if(firstPass)
                std::swap(findStr, replaceStr);
        } while(!didExit && firstPass);
        success = didExit;
        return x;
    }

}
