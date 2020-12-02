//
//  Advent of Code 2020 Solutions: Day 2
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/01/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day02.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
//#include <chrono>
#include <iostream>
//#include <fstream> //ifstream
//#include <functional> //std::function
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
//#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay02 {

    static const std::string InputFileName = "Day02.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        int sum{0};
        for(const auto& s : input) {
            if(isPasswordValid(s)) {
                sum++;
            }
        }

		return to_string(sum);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

        int sum{0};
        for(const auto& s : input) {
            if(isPasswordValid2(s)) {
                sum++;
            }
        }
        
        return to_string(sum);
    }

    bool isPasswordValid(const std::string& pwd) {
        int min{0};
        int max{0};
        char c;
        char password[100];
        sscanf(pwd.c_str(),"%d-%d %c: %s",&min,&max,&c,password);
        auto x = std::count(pwd.begin(),pwd.end(),c);
        x--;
        return (x>=min) && (x<=max);
    }
    
    bool isPasswordValid2(const std::string& pwd) {
        int min{0};
        int max{0};
        char c;
        int count{0};
        char password[100];
        sscanf(pwd.c_str(),"%d-%d %c: %s",&min,&max,&c,password);
        min--;
        max--;
        count += password[min] == c ? 1 : 0;
        count += password[max] == c ? 1 : 0;
        return count == 1;
    }
}
