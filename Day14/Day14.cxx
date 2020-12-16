//
//  Advent of Code 2020 Solutions: Day 14
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/13/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day14.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <numeric> //std::accumulate
#include <unordered_set>


using namespace std;
namespace AocDay14 {

    void generateMasks(unordered_set<int64_t>& vals, int64_t r);
    static const std::string InputFileName = "Day14.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        unordered_map<int64_t, int64_t> regs{};
        runProgram(input, regs);
        int64_t sum{0};
        for(const auto& kvp : regs) {
            sum += kvp.second;
        }
        return to_string(sum);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        unordered_map<int64_t, int64_t> regs{};
        runProgramV2(input, regs);
        int64_t sum{0};
        for(const auto& kvp : regs) {
            sum += kvp.second;
        }
        return to_string(sum);
    }

    void runProgram(const std::vector<std::string>&prog,std::unordered_map<int64_t,int64_t>&regs) {
        int64_t setMask{0};
        int64_t clearMask{0};
        for(const auto& line : prog) {
            auto words = parseLineForWords(line);
            if(line[1] == 'a') {
                //Mask value
                setMask = 0;
                clearMask = 0;
                auto itr = words[2].rbegin();
                int64_t i{0};
                while(itr != words[2].rend()) {
                    if(*itr == '1') {
                        setMask |= (1LL << i);
                    } else if(*itr == '0') {
                        clearMask |= (1LL << i);
                    }
                    itr++;
                    i++;
                }
                clearMask = ~clearMask;
            } else {
                int64_t reg{0};
                int64_t val{0};
                sscanf(line.c_str(), "mem[%lld] = %lld",&reg,&val);
                val &= clearMask;
                val |= setMask;
                regs[reg] = val;
            }
        }
    }
    
    inline void generateMasks(unordered_set<int64_t>& vals, int64_t r) {
        auto copy{vals};
        for(auto& val : vals) {
            copy.insert(val&~r);
            copy.insert(val|r);
        }
        std::swap(vals,copy);
    }
    
    void runProgramV2(const std::vector<std::string>&prog,std::unordered_map<int64_t,int64_t>&regs) {
        int64_t setMask{0};
        vector<int64_t> floatVals{};
        for(const auto& line : prog) {
            auto words = parseLineForWords(line);
            if(line[1] == 'a') {
                //Mask value
                setMask = 0;
                floatVals.clear();
                auto itr = words[2].rbegin();
                int64_t i{0};
                while(itr != words[2].rend()) {
                    if(*itr == '1') {
                        setMask |= (1LL << i);
                    } else if(*itr == 'X') {
                        floatVals.push_back(1LL <<i);
                    }
                    itr++;
                    i++;
                }
            } else {
                int64_t reg{0};
                int64_t val{0};
                sscanf(line.c_str(), "mem[%lld] = %lld",&reg,&val);
                reg |= setMask;
                unordered_set<int64_t> wRegs{reg};
                for_each(floatVals.begin(), floatVals.end(), [&wRegs](const int64_t fV){generateMasks(wRegs, fV);});
                for_each(wRegs.begin(),wRegs.end(),[&regs,&val](const int64_t rVal){regs[rVal] = val;});
            }
        }
    }
}
