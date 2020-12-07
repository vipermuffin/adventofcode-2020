//
//  Advent of Code 2020 Solutions: Day 7
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/06/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day07.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <regex>


using namespace std;
namespace AocDay07 {

    static const std::string InputFileName = "Day07.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        BagDictionary idb{};
        BagDictionary odb{};
        for(const auto& line : input) {
            updateBagDatabase(line, idb, odb);
        }
        unordered_set<string> list{};
        findContainingBags(odb, list, "shiny gold");
		return to_string(list.size());
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        BagDictionary idb{};
        BagDictionary odb{};
        for(const auto& line : input) {
            updateBagDatabase(line, idb, odb);
        }

        return to_string(findNestedBags(idb, "shiny gold"));
    }

    void updateBagDatabase(const std::string& line, BagDictionary& inDb, BagDictionary& outDb) {
        regex input_regex("(\\w+ \\w*) bags contain");
        regex output_regex("([0-9]+) (\\w+ \\w*) bags*");
        auto iBegin = sregex_iterator(line.begin(),line.end(),input_regex);
        auto iEnd = std::sregex_iterator();
        std::smatch match = *iBegin;
        string inputBag{(*iBegin)[1].str()};
        iBegin = sregex_iterator(line.begin(),line.end(),output_regex);
        while(iBegin != iEnd) {
            std::smatch match = *iBegin;
            outDb[match[2]].emplace_back(inputBag,1);
            inDb[inputBag].emplace_back(match[2],stoi(match[1]));
            iBegin++;
        }
    }
    
    void findContainingBags(const BagDictionary& outDb,std::unordered_set<std::string>& bags,const std::string& bagName) {
        if(outDb.count(bagName) > 0) {
            for(const auto& p : outDb.at(bagName)) {
                bags.insert(p.first);
                findContainingBags(outDb, bags, p.first);
            }
        }
    }
    
    int32_t findNestedBags(const BagDictionary& inDb,const std::string& bagName) {
        int32_t x{0};
        if(inDb.count(bagName) > 0) {
            for(const auto& p : inDb.at(bagName)) {
                x += p.second + p.second * findNestedBags(inDb, p.first);
            }
        }
        return x;
    }
}
