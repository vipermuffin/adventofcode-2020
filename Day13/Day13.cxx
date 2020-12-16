//
//  Advent of Code 2020 Solutions: Day 13
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/12/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day13.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <functional> //std::function
#include <numeric> //std::accumulate
#include <unordered_map>


using namespace std;
namespace AocDay13 {

    static const std::string InputFileName = "Day13.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);

		return to_string(findEarliestBus(input[1], stoi(input[0])));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);

		return to_string(findEarliestTimestamp(input[1],100000000000000));
    }

    int32_t findEarliestBus(const std::string& schedule, const int32_t minTime) {
        auto s = parseCsvLineForWords(schedule);
        
        vector<int32_t> busIds{};
        busIds.reserve(s.size());
        for_each(s.begin(), s.end(), [&busIds](const string& id){if(id != "x"){busIds.push_back(stoi(id));}});
        
        int32_t minResult{INT_MAX};
        int32_t minId{-1};
        for(const auto& val : busIds) {
            int32_t x{0};
            while(x < minTime) {
                x += val;
            }
            if(x < minResult) {
                minResult = x;
                minId = val;
            }
        }
        
        return (minResult-minTime)*minId;
    }
    
#ifndef TAKE_FOREVER
    // https://stackoverflow.com/a/8498251/531719
    // Modpow (a, b, )
    template <typename T>
    T ModPow(T Base, T Exp, T Modulo)
    {
        Base %= Modulo;
        T Result = T(1);
        while (Exp > 0)
        {
            if (Exp & 1) Result = (Result * Base) % Modulo;
            Base = (Base * Base) % Modulo;
            Exp >>= 1;
        }
        return Result;
    }

    int64_t findEarliestTimestamp(const std::string& schedule, const int64_t initVal) {
        auto s = parseCsvLineForWords(schedule);
        vector<int64_t> busIds{};
        vector<int64_t> delay{};
        int64_t d{0},product{1},sum{0};
        busIds.reserve(s.size());
        for_each(s.begin(), s.end(), [&](const string& id){
            if(id != "x"){
                auto i = stol(id);
                busIds.push_back(i);
                delay.push_back(d);
                product *= i;
            }
            d++;
        });
        
        for(int i = 0; i < busIds.size();i++) {
            int64_t P = product / busIds[i];
            sum += (busIds[i]-delay[i]) * P * ModPow(P, busIds[i]-2, busIds[i]);
        }
        return sum%product;
    }
#else
    int64_t findEarliestTimestamp(const std::string& schedule, const int64_t initVal) {
        auto s = parseCsvLineForWords(schedule);

        vector<int64_t> busIds{};
        vector<int64_t> delay{};
        int64_t d{0};
        busIds.reserve(s.size());
        for_each(s.begin(), s.end(), [&](const string& id){
            if(id != "x"){
                auto i = stol(id);
                busIds.push_back(i);
                delay.push_back(d);
            }
            d++;
            });

        bool done{false};
        int64_t timestamp{0};
        int64_t primaryInc = busIds.front();//*maxValItr;

        if(initVal != 0) {
            timestamp = initVal/primaryInc;
            timestamp *= primaryInc;
        }
        auto sz = busIds.size();
        auto inc{delay};
        for(int i = 0;i < inc.size();i++) {
            inc[i] = 1+(delay[i]/busIds[i]);
        };
        
        while(!done) {
            timestamp += primaryInc;
            size_t count{1};
            for(int32_t i = 1; i < busIds.size(); i++) {
                int64_t x = timestamp/busIds[i];
                x *= busIds[i];
                x += busIds[i]*inc[i] ;
                if(x-timestamp == delay[i]) {
                    count++;
                } else {
                    break;
                }
            }
            done = count == sz;
        }


        return timestamp;//-primaryD;
    }
#endif
}
