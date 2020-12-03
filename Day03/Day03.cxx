//
//  Advent of Code 2020 Solutions: Day 3
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/02/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day03.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
//#include <functional> //std::function
//#include <iomanip> //setfill setw hex
//#include <map>
//#include <math.h> //sqrt
#include <numeric> //std::accumulate
//#include <queue>
//#include <regex>
//#include <set>
//#include <sstream>
//#include <thread>
//#include <tuple>
//#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay03 {

    static const std::string InputFileName = "Day03.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        int32_t x = -3;
        int32_t count = 0;
        for(const auto& line : input) {
            x+=3;
            if(x >= line.size()) {
                x -= line.size();
            }
            count += line[x] == '#' ? 1 : 0;
        }

		return to_string(count);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        int32_t x = -3;
        int32_t count = 0;
        vector<int32_t> vals{};
        for(const auto& line : input) {
            x+=3;
            if(x >= line.size()) {
                x -= line.size();
            }
            count += line[x] == '#' ? 1 : 0;
        }
        vals.push_back(count);
        x = -1;
        count = 0;
        for(const auto& line : input) {
            x+=1;
            if(x >= line.size()) {
                x -= line.size();
            }
            count += line[x] == '#' ? 1 : 0;
        }
        vals.push_back(count);
        x = -5;
        count = 0;
        for(const auto& line : input) {
            x+=5;
            if(x >= line.size()) {
                x -= line.size();
            }
            count += line[x] == '#' ? 1 : 0;
        }
        vals.push_back(count);
        x = -7;
        count = 0;
        for(const auto& line : input) {
            x+=7;
            if(x >= line.size()) {
                x -= line.size();
            }
            count += line[x] == '#' ? 1 : 0;
        }
        vals.push_back(count);
        
        x = 0;
        count = 0;
        auto itr = input.begin()+2;
        while(itr < input.end()) {
            x++;
            if(x >= itr->size()) {
                x -= itr->size();
            }
            count += (*itr)[x] == '#' ? 1 : 0;
            itr+=2;
        }
        vals.push_back(count);
        
        return to_string(accumulate(vals.begin(), vals.end(), 1,multiplies<int32_t>()));
    }

}
