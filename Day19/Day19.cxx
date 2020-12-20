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
//#include <array>
#include <climits>   //INT_MIN, INT_MAX, etc.
//#include <chrono>
//#include <iostream>
//#include <fstream> //ifstream
//#include <functional> //std::function
//#include <iomanip> //setfill setw hex
//#include <map>
//#include <math.h> //sqrt
//#include <numeric> //std::accumulate
//#include <queue>
#include <regex>
#include <set>
//#include <sstream>
//#include <thread>
//#include <tuple>
//#include <unordered_map>
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
        int32_t minLength = INT32_MAX;
        int32_t maxLength = 0;
        rules = rb[0];
        sort(rules.begin(),rules.end());
//        for(const auto& rule : rules) {
//            auto sz = rule.size();
//            if(sz < minLength) {
//                minLength = sz;
//            } else if(sz > maxLength) {
//                maxLength = sz;
//            }
//        }
        
//        cout << minLength << ":" << maxLength << endl;
        while(itr != input.end()) {
            if(binary_search(rules.begin(), rules.end(), *itr)) {
                count++;
//                cout << *itr << endl;
            }
//            if(itr->size() > maxLength) {
//                maxLength = itr->size();
//            } else if(itr->size() < minLength) {
//                minLength = itr->size();
//            }
            itr++;
        }
//        cout << minLength << ":" << maxLength << endl;
		return to_string(count);
    }

    std::string solveb() { //487 too high
        auto input = parseFileForLines(InputFileName);
        auto itr = input.begin();
        while(itr != input.end() && itr->find(":") != string::npos) {
            itr++;
        }
        std::vector<string> rules{input.begin(),itr};
//        rules.push_back("200: 8 8"); // Rule 8 1st loop
//        rules.push_back("201: 8 200"); // Rule 8 2nd loop
//        rules.push_back("202: 8 201"); // Rule 8 3rd loop
//        rules.push_back("203: 8 202"); // Rule 8 4th loop
//        rules.push_back("204: 42 11");
//        rules.push_back("205: 204 31"); // Rule 11 1st loop
//        rules.push_back("206: 42 205");
//        rules.push_back("207: 206 31"); // Rule 11 2nd loop
//        rules.push_back("222: 0 | 200 11 | 200 205 | 200 207 | 201 11 | 201 205 | 201 207 | 202 11 | 202 205 | 202 207 | 203 11 | 203 205 | 203 207");
//        rules.push_back("222: 0 | 200 11 | 8 205");
        RuleBook rb = ruleBuilder(rules);
        RuleBook rb2{};
//        std::swap(rb2[0],rb[0]);
        std::swap(rb2[11],rb[11]);
        std::swap(rb2[42],rb[42]);
        std::swap(rb2[31],rb[31]);
        rb.clear();
//        rb2[0].reserve(rb2[0].size()*rb2[0].size());
//        for(const auto& s8 : rb2[42]) {
//            for(const auto& s11 : rb2[11]) {
//                auto new8{s8};
//                auto new11{s11};
//                rb2[0].push_back(new8+s11);
//                for(int i = 1; i < 3; i++) {
//                    new8.append(s8);
//                    rb2[0].push_back(new8+s11);
//                    for(int j = 1; j < 3;j++) {
//
//                    }
//                }
//            }
//        }
        
//        sort(rb2[0].begin(),rb2[0].end());
        //Build regex list
        vector<regex> rgxs{};
        for(const auto& s1 : rb2[42]) {
            for(const auto& s2 : rb2[31]) {
                for(const auto& s3 : rb2[42]) {
                    rgxs.emplace_back("^("+s1+")+"+"("+s3+")+"+"("+s2+")+$");
                }
//                string s{"^("+s1+")+"+"("+s1+")+"+"("+s2+")+$"};
//                cout << s << endl;
//                rgxs.emplace_back(s);
            }
        }
        int32_t count{0};
        auto iEnd = std::sregex_iterator();
        while(itr != input.end()) {
            for(const auto& input_regex : rgxs) {
                auto iBegin = sregex_iterator(itr->begin(),itr->end(),input_regex);
                if(iBegin != iEnd) {
                    count++;
                    cout << count;
                    break;
                }
            }
            itr++;
            cout << '.';
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
        set<int32_t> updated{};
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
//        regex tmp_regex("([0-9]+)");
//        iBegin = sregex_iterator(line.begin(),line.end(),tmp_regex);
//        int idx{0};
//        std::pair<int32_t,int32_t> p{INVALID,INVALID};
//        auto tId{INVALID};
//        while(iBegin != iEnd) {
//            std::smatch match = *iBegin;
//            auto i = stoi(match[1]);
//            if(idx == 0) {
//                tId = i;
//            } else if(idx == 1) {
//                p.first = i;
//            } else {
//                p.second = i;
//                trb[tId].push_back(p);
//                p.first = INVALID;
//                p.second = INVALID;
//                idx = 0;
//            }
//            idx++;
//            iBegin++;
//        }
//        if(idx == 2) {
//            trb[tId].push_back(p);
//        }
    }
}
