//
//  Advent of Code 2020 Solutions: Day 1
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 11/30/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day01.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.


using namespace std;
namespace AocDay01 {

    static const std::string InputFileName = "Day01.txt";
    std::string solvea() {
        auto input = parseFileForNumberPerLine(InputFileName);
        std::sort(input.begin(),input.end());
        auto fItr = input.begin();
        auto rItr = input.rbegin();
        while(fItr != input.end()) {
            while(rItr != input.rend()) {
                if((fItr != rItr.base()-1) &&
                   ((*fItr + *rItr) == 2020)) {
                    return to_string(*fItr**rItr);
                }
                rItr++;
            }
            rItr = input.rbegin();
            fItr++;
        }
		return "---";
    }

    std::string solveb() {
        auto input = parseFileForNumberPerLine(InputFileName);
        std::sort(input.begin(),input.end());
        auto fItr = input.begin();
        auto fItr2 = input.begin();
        auto rItr = input.rbegin();
        while(fItr != input.end()) {
            while(fItr2 != input.end()) {
                while(rItr != input.rend()) {
                    if(((fItr != rItr.base()-1)&&(fItr != fItr2)) &&
                       ((*fItr + *fItr2 + *rItr) == 2020)) {
                        return to_string(*fItr**rItr**fItr2);
                    }
                    rItr++;
                }
                rItr = input.rbegin();
                fItr2++;
            }
            fItr2 = input.begin();
            fItr++;
        }

		return "---";
    }

}
