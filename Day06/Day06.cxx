//
//  Advent of Code 2020 Solutions: Day 6
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/05/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day06.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <numeric> //std::accumulate
#include <sstream>
#include <unordered_map>
#include <unordered_set>


using namespace std;
namespace AocDay06 {

    static const std::string InputFileName = "Day06.txt";
    static const char FS = ',';
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto grps = buildGroupStrings(input);

        return to_string(countAnyYesPerGroup(grps));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        auto grps = buildGroupStrings(input);
        
        return to_string(countAllYesPerGroup(grps));
    }

    std::vector<std::string> buildGroupStrings(const std::vector<std::string>& input) {
        vector<string> groups{};
        stringstream ss{};
        for(const auto& line : input) {
            if(line.size() == 0) {
                groups.push_back(ss.str());
                ss = stringstream{};
            } else {
                ss.str().size() > 0 ? ss << FS << line : ss << line;
            }
        }
        groups.push_back(ss.str());
        return groups;
    }
    
    int32_t countAnyYesPerGroup(const std::vector<std::string>& grps) {
        vector<int32_t> counts{};
        for_each(grps.begin(), grps.end(), [&](const string& g){
            unordered_set<char> yesList{};
            for_each(g.begin(), g.end(), [&](const char& c){if(c != FS) yesList.insert(c);});
            counts.push_back(yesList.size());
        });
        return accumulate(counts.begin(),counts.end(),0);
    }
    
    int32_t countAllYesPerGroup(const std::vector<std::string>& grps) {
        vector<int32_t> counts{};
        for_each(grps.begin(), grps.end(), [&](const string& g){
            unordered_map<char, int32_t> yesMap{};
            int32_t count{0};
            for_each(g.begin(), g.end(), [&](const char& c){yesMap[c]++;});
            for_each(yesMap.begin(),yesMap.end(),[&](const std::pair<char,int32_t>& kvp){count += kvp.second == (yesMap[FS]+1) ? 1 : 0;});
            counts.push_back(count);
        });
        
        return accumulate(counts.begin(),counts.end(),0);
    }
}
