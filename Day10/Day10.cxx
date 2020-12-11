//
//  Advent of Code 2020 Solutions: Day 10
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/09/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day10.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <numeric> //std::accumulate
#include <set>
#include <unordered_map>


using namespace std;
namespace AocDay10 {

    static const std::string InputFileName = "Day10.txt";
    std::string solvea() {
        auto input = parseFileForNumberPerLine(InputFileName);
        input.push_back(0);
        std::sort(input.begin(),input.end());
        input.push_back(input.back()+3);
        unordered_map<int,int> x;
        auto itr = input.begin()+1;
        while(itr != input.end()) {
            auto y = *itr - *(itr-1);
            x[y]++;
            itr++;
        }
        return to_string(x[1]*x[3]);
    }

    std::string solveb() {
        auto input = parseFileForNumberPerLine(InputFileName);
		return to_string(findAllCombos(input));
    }
    
    int64_t findAllCombos(std::vector<int32_t>& input) {
        input.push_back(0);
        std::sort(input.begin(),input.end());
        input.push_back(input.back()+3);
        vector<int64_t> tmp{};
        set<int> perm{0,input.back()};
        auto itr = input.begin()+1;
        //Find all permanent adapters...anything with gap of 3
        while(itr < input.end()) {
            if(*itr-*(itr-1) == 3) {
                perm.insert(*(itr-1));
                perm.insert(*itr);
            }
            itr++;
        }
        
        //Find all removable ones
        //1 in a row results in 2 combinations
        //2 in a row results in 4 combinations
        //3 in a row results in 7 combinations
        itr = input.begin()+1;
        vector<int64_t> cmboMul{1,2,4,7};
        int count{0};
        while(itr < input.end()) {
            if(perm.count(*itr++) > 0) {
                tmp.push_back(cmboMul[count]);
                count = 0;
            } else {
                count++;
            }
        }
        return std::accumulate(tmp.begin(), tmp.end(), static_cast<int64_t>(1),multiplies<int64_t>());
    }
}
