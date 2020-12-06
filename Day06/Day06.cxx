//
//  Advent of Code 2020 Solutions: Day 6
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/05/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day06.h"
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
#include <unordered_map>
#include <unordered_set>


using namespace std;
namespace AocDay06 {

    static const std::string InputFileName = "Day06.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        unordered_set<char> yesList{};
        vector<int32_t> counts{};
        for(const auto& line : input) {
            if(line=="") {
                counts.push_back(yesList.size());
                yesList.clear();
            } else {
                for(const auto& c : line) {
                    yesList.insert(c);
                }
            }
        }
        counts.push_back(yesList.size());
        return to_string(accumulate(counts.begin(),counts.end(),0));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        unordered_map<char, int32_t> yesList{};
        vector<int32_t> counts{};
        int32_t numPeople{0};
        for(const auto& line : input) {
            if(line=="") {
                int32_t count{0};
                for(const auto& kvp : yesList) {
                    count += kvp.second == numPeople ? 1 : 0;
                }
                counts.push_back(count);
                yesList.clear();
                numPeople = 0;
            } else {
                numPeople++;
                for(const auto& c : line) {
                    yesList[c]++;
                }
            }
        }
        int32_t count{0};
        for(const auto& kvp : yesList) {
            count += kvp.second == numPeople ? 1 : 0;
        }
        counts.push_back(count);

        return to_string(accumulate(counts.begin(),counts.end(),0));
    }

}
