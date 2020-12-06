//
//  Advent of Code 2020 Solutions: Day 4
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/03/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day04.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <sstream>


using namespace std;
namespace AocDay04 {

    static const std::string InputFileName = "Day04.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        vector<string> passportStrings{};
        int32_t count{0};
        buildPassportStrings(input, passportStrings);
        for(const auto& passport : passportStrings) {
            unordered_map<string, string> pp{};
            updatePassportMap(passport, pp);
            count += passportIsValid(pp) ? 1 : 0;
        }
		return to_string(count);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        vector<string> passportStrings{};
        int32_t count{0};
        buildPassportStrings(input, passportStrings);
        for(const auto& passport : passportStrings) {
            unordered_map<string, string> pp{};
            updatePassportMap(passport, pp);
            count += passportIsValid2(pp) ? 1 : 0;
        }
        return to_string(count);
    }

    void buildPassportStrings(const std::vector<std::string>&input,std::vector<std::string>&output) {
        stringstream ss{};
        auto itr = input.begin();
        while(itr != input.end()) {
            if(itr->size() > 0) {
                if(ss.str().size() > 0) {
                    ss << " " << *itr;
                } else {
                    ss << *itr;
                }
            } else {
                output.push_back(ss.str());
                ss = stringstream{};
            }
            itr++;
        }
        if(ss.str().size() > 0) {
            output.push_back(ss.str());
        } 
    }
    
    void updatePassportMap(const std::string &input,std::unordered_map<std::string,std::string>&output) {
        auto x = parseLineForWords(input);
        for(const auto& kvp : x) {
            auto idx = kvp.find(":");
            string key{kvp.begin(),kvp.begin()+idx};
            string val{kvp.begin()+idx+1,kvp.end()};
            output[key] = val;
        }
    }
    
    bool passportIsValid(const std::unordered_map<std::string, std::string>&input) {
        bool valid = true;
        std::vector<string> validKeys{"byr","iyr","eyr","hgt","hcl","ecl","pid"};

        for(const auto& key : validKeys) {
            if(input.count(key) == 0) {
                return false;
            }
        }
        
        return valid;
    }
    
    bool passportIsValid2(const std::unordered_map<std::string, std::string>&input) {
        bool valid = true;
        std::vector<string> validKeys{"byr","iyr","eyr","hgt","hcl","ecl","pid"};
        
        if(!passportIsValid(input)) {
            return false;
        }
        
        if(input.count("byr") > 0) {
            auto x = stoi(input.at("byr"));
            if(x < 1920 || x > 2002) {
                return false;
            }
        }
        
        if(input.count("iyr") > 0) {
            auto x = stoi(input.at("iyr"));
            if(x < 2010 || x > 2020) {
                return false;
            }
        }
        
        if(input.count("eyr") > 0) {
            auto x = stoi(input.at("eyr"));
            if(x < 2020 || x > 2030) {
                return false;
            }
        }
        
        if(input.count("hgt") > 0) {
            auto s = input.at("hgt");
            auto x = stoi(s);
            string y{s.end()-2,s.end()};
            if(y == "cm") {
                if(x < 150 || x > 193) {
                    return false;
                }
            } else if(y == "in") {
                if(x < 59 || x > 76) {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        
        if(input.count("hcl") > 0) {
            auto x = input.at("hcl");
            if(x.size() == 7 && x[0] == '#'){
                auto itr = x.begin()+1;
                while(itr != x.end()) {
                    if((*itr >= '0' && *itr <= '9') ||
                       (*itr >= 'a' && *itr <= 'f')) {
                        //Valid
                    } else {
                        return false;
                    }
                    itr++;
                }
            }
            else {
                return false;
            }
        }
        
        if(input.count("ecl") > 0) {
            auto s = input.at("ecl");
            vector<string> validEcl{"amb","blu","brn","gry","grn","hzl","oth"};
            if(count(validEcl.begin(),validEcl.end(),s) != 1) {
                return false;
            }
        }
        
        if(input.count("pid") > 0) {
            auto x = input.at("pid");
            if(x.size() == 9){
                auto itr = x.begin();
                while(itr != x.end()) {
                    if((*itr >= '0' && *itr <= '9')) {
                        //Valid
                    } else {
                        return false;
                    }
                    itr++;
                }
            }
            else {
                return false;
            }
        }
        
        return valid;
    }
}
