//
//  Advent of Code 2020 Solutions: Day 16
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/15/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day16.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <numeric> //std::accumulate
#include <regex>
#include <unordered_set>


using namespace std;
namespace AocDay16 {

    static const std::string InputFileName = "Day16.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        TicketDb database{};
        auto itr = input.begin();
        //Parse Rules
        while(itr != input.end() && *itr != "nearby tickets:") {
            parseTicketRule(*itr, database);
            itr++;
        }
        itr++;
        
        //Parse Ranges
        auto ranges = buildRangeList(database);
        
        //Parse Invalid Values
        vector<int32_t> invalid{};
        while(itr != input.end()) {
            auto vals = parseCsvLineForNum(*itr);
            isValidList(vals, ranges, invalid);
            itr++;
        }
        return to_string(std::accumulate(invalid.begin(), invalid.end(), 0));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        
        //Parse Rules
        TicketDb database{};
        vector<int32_t> myTicket{};
        auto itr = input.begin();
        while(itr != input.end() && *itr != "nearby tickets:") {
            if(*itr == "your ticket:") {
                ++itr;
                myTicket = parseCsvLineForNum(*itr);
            } else {
                parseTicketRule(*itr, database);
            }
            itr++;
        }
        itr++;
        
        //Parse Ranges
        auto ranges = buildRangeList(database);
        
        //Find Valid Tickets
        vector<int32_t> invalid{};
        vector<vector<int32_t>> validTickets{};
        while(itr != input.end()) {
            auto vals = parseCsvLineForNum(*itr);
            if(isValidList(vals, ranges, invalid)) {
                validTickets.push_back(vals);
            }
            itr++;
        }
        
        //Find which fields could be which
        unordered_map<string, vector<int32_t>> fieldMap{};
        for(const auto& kvp : database) {
            TicketDb tmp{};
            tmp[kvp.first] = kvp.second;
            RangeList fieldRanges = buildRangeList(tmp);
            for(int32_t i = 0; i < validTickets.front().size();i++) {
                vector<int32_t> fieldVals{};
                vector<int32_t> invalid{};
                for(const auto& ticket : validTickets) {
                    fieldVals.push_back(ticket[i]);
                }
                if(isValidList(fieldVals, fieldRanges, invalid)) {
                    fieldMap[kvp.first].push_back(i);
                }
            }
        }
        
        //Determine actual field
        int32_t sz = validTickets.front().size();
        unordered_set<int32_t> foundFieldIdx{};
        while(sz != 0) {
            sz = validTickets.front().size();
            for(auto& kvp : fieldMap) {
                if(kvp.second.size() == 1) {
                    sz--;
                    foundFieldIdx.insert(kvp.second.front());
                } else {
                    for(const auto& i : foundFieldIdx) {
                        auto itr = find(kvp.second.begin(),kvp.second.end(),i);
                        if(itr != kvp.second.end()) {
                            kvp.second.erase(itr);
                        }
                    }
                }
            }
            
        }
        //Find product of all Departure
        int64_t product{1};
        for(const auto& kvp : fieldMap) {
            if(kvp.first.find("departure") != string::npos) {
                product *= myTicket[kvp.second.front()];
            }
        }
		return to_string(product);
    }

    void parseTicketRule(const std::string& line, TicketDb& database) {
        auto idx = line.find(":");
        if(idx == string::npos) return;
        string inputType{line.begin(),line.begin()+idx};
        regex input_regex("([0-9]+)-([0-9]+)");// or ([0-9]+)-([0-9]+)");
        auto iBegin = sregex_iterator(line.begin(),line.end(),input_regex);
        auto iEnd = std::sregex_iterator();
        while(iBegin != iEnd) {
            std::smatch match = *iBegin;
            database[inputType].emplace_back(stoi((*iBegin)[1].str()),stoi((*iBegin)[2].str()));
            iBegin++;
        }
    }
    
    RangeList buildRangeList(const TicketDb& database) {
        RangeList pv{};
        pv.reserve(database.size()*3);
        for(const auto& dbi : database) {
            for(const auto& p : dbi.second) {
                pv.push_back(p);
            }
        }
        std::sort(pv.begin(),pv.end());
        RangeList validRanges{};
        std::pair<int32_t,int32_t> validRange{pv.front().first,pv.front().second};
        for(const auto& p : pv) {
            if(p.first > validRange.second) {
                validRanges.push_back(validRange);
                validRange.first = p.first;
                validRange.second = p.second;
            } else {
                
            }
            validRange.second = p.second > validRange.second ? p.second : validRange.second;
        }
        validRanges.push_back(validRange);
        return validRanges;
    }
    
    bool isValidList(const std::vector<int32_t>& vals,const RangeList& validRanges, std::vector<int32_t>& invalidVals) {
        bool valid = true;
        auto itr = vals.begin();
        while(itr != vals.end()) {
            auto rItr = validRanges.begin();
            while(rItr != validRanges.end() && *itr > rItr->second) {
                rItr++;
            }
            if(rItr == validRanges.end()) {
                rItr--;
            }
            if(!((*itr >= rItr->first) && (*itr <= rItr->second))) {
                invalidVals.push_back(*itr);
                valid = false;
            }
            itr++;
        }
        return valid;
    }
}
