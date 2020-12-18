//
//  Advent of Code 2020 Solutions: Day 18
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/17/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day18.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <numeric> //std::accumulate


using namespace std;
namespace AocDay18 {

    static const std::string InputFileName = "Day18.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        std::vector<int64_t> vals;
        vals.reserve(input.size());
        for(const auto& line : input) {
            vals.push_back(evaluateExpression(line));
        }

        return to_string(std::accumulate(vals.begin(),vals.end(),0LL));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        std::vector<int64_t> vals;
        vals.reserve(input.size());
        for(const auto& line : input) {
            vals.push_back(evaluateAdvExpression(line));
        }
        
        return to_string(std::accumulate(vals.begin(),vals.end(),0LL));
    }

    int64_t evaluateExpression(const std::string& exp) {
        int64_t result{0};
        
        auto itr = exp.begin();
        char op = '+';
        while(itr < exp.end()) {
            size_t idx{0};
            auto rhs{0};
            string remaining{itr,exp.end()};
            try {
                rhs = stoi(remaining,&idx);
            } catch (exception &err) {
                //Parenthesis
                auto rItr = remaining.begin();
                idx++;
                auto idx2{idx};
                int count{1};
                while(rItr+idx2 != remaining.end() && count > 0) {
                    if(*(rItr+idx2) == ')') {
                        count--;
                    } else if (*(rItr+idx2) == '(') {
                        count++;
                    }
                    idx2++;
                }
                string subExp = remaining.substr(idx,idx2-idx-1);
                rhs = evaluateExpression(subExp);
                idx=idx2;
            }
            if(op == '+') {
                result += rhs;
            }else {
                result *= rhs;
            }
            
            itr += idx;
            while(*itr == ' ') {
                itr++;
            }
            //Get operation
            op = *(itr++);

            while(itr != exp.end() && *itr == ' ') {
                itr++;
            }
        }
        return result;
    }
    
    int64_t evaluateAdvExpression(const std::string& exp) {
        int64_t result{0};
        vector<int64_t> pendingMul{};
        auto itr = exp.begin();
        char op = '+';
        while(itr < exp.end()) {
            size_t idx{0};
            auto rhs{0};
            string remaining{itr,exp.end()};
            try {
                rhs = stoi(remaining,&idx);
            } catch (exception &err) {
                //Parenthesis
                auto rItr = remaining.begin();
                idx++;
                auto idx2{idx};
                int count{1};
                while(rItr+idx2 != remaining.end() && count > 0) {
                    if(*(rItr+idx2) == ')') {
                        count--;
                    } else if (*(rItr+idx2) == '(') {
                        count++;
                    }
                    idx2++;
                }
                string subExp = remaining.substr(idx,idx2-idx-1);
                rhs = evaluateAdvExpression(subExp);
                idx=idx2;
            }
            if(op == '+') {
                result += rhs;
            }else {
                pendingMul.push_back(result);
                result = rhs;
            }
            
            itr += idx;
            while(itr != exp.end() && *itr == ' ') {
                itr++;
            }
            //Get operation
            if(itr != exp.end()) {
                op = *(itr++);
            } else {
                op = '0';
            }
            
            while(itr != exp.end() && *itr == ' ') {
                itr++;
            }
        }
        
        for(const auto& val : pendingMul) {
            result *= val;
        }
        return result;
    }
}
