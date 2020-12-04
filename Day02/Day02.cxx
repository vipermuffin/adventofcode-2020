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
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <cstdio>


using namespace std;
namespace AocDay02 {

    static const std::string InputFileName = "Day02.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto sum = count_if(input.begin(),input.end(),isPasswordValid);

		return to_string(sum);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto sum = count_if(input.begin(),input.end(),isPasswordValid2);
        
        return to_string(sum);
    }

    bool isPasswordValid(const std::string& pwd) {
        int min{0}, max{0};
        char c;
        sscanf(pwd.c_str(),"%d-%d %c:",&min,&max,&c);
        auto x = std::count(pwd.begin(),pwd.end(),c);
        x--;
        return (x>=min) && (x<=max);
    }
    
    bool isPasswordValid2(const std::string& pwd) {
        int idx[]{0,0}, count{0};
        char c;
        char password[pwd.size()];
        sscanf(pwd.c_str(),"%d-%d %c: %s",&idx[0],&idx[1],&c,password);
        idx[0]--;
        idx[1]--;
        count += password[idx[0]] == c ? 1 : 0;
        count += password[idx[1]] == c ? 1 : 0;
        return count == 1;
    }
}
