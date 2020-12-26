//
//  Advent of Code 2020 Solutions: Day 21
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/20/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day21.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <regex>


using namespace std;
namespace AocDay21 {

    static const std::string InputFileName = "Day21.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);

		return to_string(countNonAllergens(input));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        
		return produceCanonicalDangerousList(input);
    }

    FoodDb parseFoodList(const std::vector<std::string>& input) {
        FoodDb db{};
        for(const auto& line :input) {
            parseFoodRow(line, db);
        }
        return db;
    }
    
    void parseFoodRow(const std::string& input, FoodDb& db) {
        regex input_regex("([\\w\\s]+)* \\(contains ([\\w]+)[,\\s]*(\\w*)[,\\s]*(\\w*)[,\\s]*(\\w*)[,\\s]*(\\w*)[,\\s]*\\)");
        auto iBegin = sregex_iterator(input.begin(),input.end(),input_regex);
        auto iEnd = std::sregex_iterator();
        while(iBegin != iEnd) {
            std::smatch match = *iBegin;
            if(match.size() > 1) {
                for(int i = 2; i < match.size();i++) {
                    if(match[i].str().size() > 0) {
                        db[match[i]].push_back(match[1]);
                    }
                }
            }
            iBegin++;
        }
    }
    
    FoodPairList determineFoodName(const FoodDb& db) {
        //Build potential word list
        FoodDb potential{};
        for(const auto& kvp : db) {
            unordered_map<string, int32_t> xCount{};
            for(const auto& line : kvp.second) {
                auto words = parseLineForWords(line);
                for(const auto& word : words) {
                    xCount[word]++;
                }
            }
            for(const auto& wordCountP : xCount) {
                if(wordCountP.second == kvp.second.size()) {
                    potential[kvp.first].push_back(wordCountP.first);
                }
            }
        }
        
        auto dbSz = db.size();
        while(dbSz > 0) {
            dbSz = db.size();
            vector<string> x{};
            for(const auto& kvp : potential) {
                if(kvp.second.size() == 1) {
                    x.push_back(kvp.second.front());
                }
            }
            
            if(x.size() > 0) {
                for(const auto& deadWord : x) {
                    for(auto& kvp : potential) {
                        if(kvp.second.size()!= 1) {
                            auto itr = find(kvp.second.begin(),kvp.second.end(),deadWord);
                            if(itr != kvp.second.end()) {
                                kvp.second.erase(itr);
                            }
                        }
                    }
                    dbSz--;
                }
            } else {
                cout << "ERROR";
            }
        }
        
        FoodPairList fpl{};
        for(const auto& kvp : potential) {
            fpl.emplace_back(kvp.first,kvp.second.front());
        }

        return fpl;
    }
    
    int32_t countNonAllergens(const std::vector<std::string>& input) {
        auto db = parseFoodList(input);
        auto fpl = determineFoodName(db);
        unordered_map<string, string> allergyList{};
        for(const auto& p : fpl) {
            allergyList[p.second] = p.first;
        }
        int32_t ret{0};
        
        for(const auto& row : input) {
            string line{row.begin(),row.begin()+row.find("(")};
            auto words = parseLineForWords(line);
            for(const auto& word : words) {
                if(allergyList.count(word) == 0) {
                    ret++;
                }
            }
        }
        
        return ret;
    }
    
    std::string produceCanonicalDangerousList(const std::vector<std::string>& input) {
        auto db = parseFoodList(input);
        auto fpl = determineFoodName(db);
        vector<string> allergyList{};
        sort(fpl.begin(),fpl.end());
        for(const auto& p : fpl) {
            allergyList.push_back(p.second);
        }
        string dList{};
        auto x  = allergyList.begin();
        while(x < allergyList.end()) {
            dList.append(*x++);
            dList.append(x==allergyList.end() ? "" : ",");
        }
        return dList;
    }
}
