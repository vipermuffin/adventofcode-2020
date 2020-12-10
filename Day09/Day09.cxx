//
//  Advent of Code 2020 Solutions: Day 9
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/08/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day09.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <unordered_set>
#include <fstream>

using namespace std;
namespace AocDay09 {

    static const std::string InputFileName = "Day09.txt";
    
    template <class T>
    std::vector<T> parseFileForNumbers(const std::string& fileName)
    {
        std::vector<T> spreadsheet{};
        ifstream inputFile{fileName};
        T x;
        while(inputFile >> x) {
            spreadsheet.push_back(x);
        }
        inputFile.close();
        return spreadsheet;
    }
    
    std::string solvea() {
        auto input = parseFileForNumbers<int64_t>(InputFileName);

		return to_string(findInvalidVal(input, 25));
    }

    std::string solveb() {
        auto input = parseFileForNumbers<int64_t>(InputFileName);

		return to_string(findInvalidValMatch(input, findInvalidVal(input, 25)));
    }
    
    bool isValid(const std::vector<int64_t>&vals,const int64_t val) {
        CombinationGenerator<int64_t> x{vals};
        auto combos = x.generateCombosChoose(2);
        unordered_set<int64_t> list{};
        for(const auto& p : combos) {
            list.insert(p.front()+p.back());
        }
        return list.count(val) > 0;
    }
    
    int64_t findInvalidVal(const std::vector<int64_t>& vals, const int64_t preamble) {
        if(preamble > vals.size()) {
            return -222;
        }
        auto head = vals.begin();
        auto end = vals.begin()+preamble;
        
        while(end != vals.end()) {
            vector<int64_t> previous{head,end};
            if(!isValid(previous, *end)) {
                return *end;
            }
            head++;
            end++;
        }
        
        return -222;
    }
    
    int64_t findInvalidValMatch(const std::vector<int64_t>& vals, const int64_t match) {
        auto head = vals.begin();
        auto end = vals.begin()+1;
        
        do {
            int64_t sum{*head};
            while(sum < match && end != vals.end()) {
                sum += *end++;
                if(sum==match) {
                    vector<int64_t> x{head,end};
                    std::sort(x.begin(),x.end());
                    return x.front()+x.back();
                }
            }
            head++;
            end = head+1;
        }while(head != vals.end());
        
        return -222;
    }

}
