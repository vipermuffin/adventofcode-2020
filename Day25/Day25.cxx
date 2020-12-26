//
//  Advent of Code 2020 Solutions: Day 25
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/26/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day25.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.

using namespace std;
namespace AocDay25 {

    static const std::string InputFileName = "Day25.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto loop = findLoopSize(stoll(input[0]));
		return to_string(findSecretKey(stoll(input[1]), loop));
    }

    std::string solveb() {
		return "---";
    }

    int32_t findLoopSize(int64_t publicKey) {
        int64_t val{1};
        int32_t loop{0};
        while(val != publicKey) {
            val *= 7;
            val %= 20201227;
            loop++;
        }
        return loop;
    }
    
    int32_t findSecretKey(int64_t publicKey, int32_t loopsize) {
        int64_t val{1};
        for(;loopsize > 0;loopsize--) {
            val *= publicKey;
            val %= 20201227;
        }
        return static_cast<int32_t>(val);
    }
}
