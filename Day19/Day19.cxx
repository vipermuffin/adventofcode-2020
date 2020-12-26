//
//  Advent of Code 2020 Solutions: Day 19
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/18/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day19.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <regex>
#include <unordered_set>

using namespace std;
namespace AocDay19 {

    static const std::string InputFileName = "Day19.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto itr = input.begin();
        while(itr != input.end() && itr->find(":") != string::npos) {
            itr++;
        }
        std::vector<string> rules{input.begin(),itr};
        RuleBook rb = ruleBuilder(rules);

        int32_t count{0};
        std::swap(rules,rb[0]);
        sort(rules.begin(),rules.end());
        
        while(itr != input.end()) {
            if(binary_search(rules.begin(), rules.end(), *itr)) {
                count++;
            }
            itr++;
        }
		return to_string(count);
    }

    std::string solveb() { //417, 487 too high
        auto input = parseFileForLines(InputFileName);
        auto itr = input.begin();
        while(itr != input.end() && itr->find(":") != string::npos) {
            itr++;
        }
        std::vector<string> rules{input.begin(),itr};
        RuleBook rb = ruleBuilder(rules);
        //For my input
        //  0: 8 11
        //  8: 42
        // 11: 42 31
        // The input at minimum should be 42 42 31
        //  8: 42 | 42 8
        // 11: 42 31 | 42 11 31 --> 42*x 31*x
        // Need at least one more 42 than 31
        vector<string> r42{},r31{};
        std::swap(r42,rb[42]);
        std::swap(r31,rb[31]);
        std::sort(r42.begin(),r42.end());
        std::sort(r31.begin(),r31.end());
        rb.clear();
        size_t len42 = r42.front().size();
        size_t len31 = r31.front().size();
        if(len42 != len31) {
            return "ERROR";
        }
        
        int32_t count{0};
        while(itr != input.end()) {
            int32_t r42_count{0};
            int32_t r31_count{0};
            bool count31 = false;
            for(int i = 0; i < itr->size();i += len42) {
                string s = itr->substr(i,len42);
                if(!count31) {
                    if(binary_search(r42.begin(), r42.end(), s)) {
                        r42_count++;
                    } else {
                        count31 = true;
                        if(binary_search(r31.begin(), r31.end(), s)) {
                            r31_count++;
                        }
                    }
                } else {
                    if(binary_search(r31.begin(), r31.end(), s)) {
                        r31_count++;
                    } else {
                        r42_count = 0;
                        break;
                    }
                }
            }
            
            if(r31_count != 0 && r42_count > r31_count) {
                count++;
            }
            itr++;
        }
        
        return to_string(count);
    }

    RuleBook ruleBuilder(const std::vector<std::string>& input) {
        RuleBook rb{};
        tempRuleBook trb{};
        for(const auto& line : input) {
            readRule(line, rb, trb);
        }
        
        auto sz = trb.size();
        unordered_set<int32_t> updated{};
        while(sz > 0) {
            int32_t uVals{0};
            for(const auto& kvp : trb) {
                if(updated.count(kvp.first) == 0) {
                    bool complete = true;
                    for(const auto& p : kvp.second) {
                        if(rb.count(p.first) == 0) complete = false;
                        if(p.second != INVALID && rb.count(p.second) == 0) complete = false;
                    }
                    if(complete) {
                        sz--;
                        rb[kvp.first].reserve(rb.at(kvp.second.front().first).size()*rb.at(kvp.second.back().first).size());
                        for(const auto& p : kvp.second) {
                            if(p.second != INVALID) {
                                for(const auto& v : rb.at(p.second)) {
                                    auto rules = rb.at(p.first);
                                    for(auto& rule : rules) {
                                        rule.append(v);
                                        rb[kvp.first].push_back(rule);
                                    }
                                }
                            } else {
                                auto rules = rb.at(p.first);
                                for(auto& rule : rules) {
                                    rb[kvp.first].push_back(rule);
                                }
                            }
                        }
                        updated.insert(kvp.first);
                        uVals++;
                    }
                }
            }
            if(uVals==0) {
                printVector(rb.at(11));
                printVector(rb.at(8));
            }
        }
        return rb;
    }
    
    void readRule(const std::string& line,RuleBook& rb,tempRuleBook& trb) {
        regex input_regex("\"(\\w+)\"");
        auto iBegin = sregex_iterator(line.begin(),line.end(),input_regex);
        auto iEnd = std::sregex_iterator();
        if(iBegin != iEnd) {
            //concrete rule
            string rule{(*iBegin)[1].str()};
            auto id = stoi(line);
            rb[id].push_back(rule);
            return;
        }
        
        //Temp rule
        size_t idx{0};
        int32_t id = stoi(line,&idx);
        std::pair<int32_t,int32_t> p{INVALID,INVALID};
        auto itr = line.begin()+idx+1;
        while(itr < line.end()) {
            while(*itr == ' ') {
                itr++;
            }
            if(*itr == '|') {
                if(p.first != INVALID) {
                    trb[id].push_back(p);
                    p.first = INVALID;
                    p.second = INVALID;
                }
                itr++;
            } else {
                auto i = stoi(string(itr,line.end()),&idx);
                if(p.first == INVALID) {
                    p.first = i;
                } else {
                    p.second = i;
                    trb[id].push_back(p);
                    p.first = INVALID;
                    p.second = INVALID;
                }
                itr+=idx;
            }
        }
        if(p.first != INVALID) {
            trb[id].push_back(p);
            p.first = INVALID;
            p.second = INVALID;
        }
    }
}
