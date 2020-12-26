//
//  Advent of Code 2020 Solutions: Day 23
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/22/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day23.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.


using namespace std;
namespace AocDay23 {
    constexpr int32_t N = 1000000;
    constexpr int32_t NUM_RUNS = 10000000;
    
    static const std::string InputFileName = "Day23.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        list<int32_t> order{};
        for(const auto& c : input[0])
            order.push_back(static_cast<int32_t>(c-'0'));

		return playGame(order, 100);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        list<int32_t> order{};
        for(const auto& c : input[0])
            order.push_back(static_cast<int32_t>(c-'0'));
        for(int i = 10; i <= N; i++ ) {
            order.push_back(i);
        }

        return to_string(playGame2(order, NUM_RUNS));
    }

    std::string playGame(std::list<int32_t>& order,int32_t rounds) {
        playGame2(order,rounds);
        
        auto it = order.begin();
        
        string retVal(order.size()-1,'0');
        it = find(order.begin(),order.end(),1);
        for(int i = 0; i < order.size()-1;i++) {
            it++;
            if(it == order.end()) {
                it = order.begin();
            }
            retVal[i] = static_cast<char>('0'+*it);
        }
        return retVal;
    }
    
    int64_t playGame2(std::list<int32_t>& order,int32_t rounds) {
        int32_t minVal = 1;
        int32_t maxVal = order.size();
        vector<list<int32_t>::iterator> its;
        its.resize(order.size()+1,order.begin());
        
        auto it = order.begin();
        while(it != order.end()) {
            //Using std::advance.  its[*it] = it++; resulted in a bad array of iterators
            its[*it] = it;
            std::advance(it, 1);
        }
        
        it = order.begin();
        for(int i = 0; i < rounds; i++) {
            list<int32_t> x{};
            for(int j = 0; j < 3;j++) {
                auto cpy = std::next(it);
                if(cpy == order.end()) {
                    cpy = order.begin();
                }
                x.splice(std::next(x.begin(),j), order, cpy, std::next(cpy));
            }
            auto destVal = *it - 1;
            if(destVal < minVal) {
                destVal = maxVal;
            }
            while(find(x.begin(),x.end(),destVal) != x.end()) {
                destVal--;
                if(destVal < minVal) {
                    destVal = maxVal;
                }
            }
            
            auto itr = std::next(its[destVal]);
            order.splice(itr, x);
            for(int j = 1; j < 4; j++) {
                itr = std::next(its[destVal],j);
                its[*itr] = itr;
            }
            std::advance(it, 1);
            if(it == order.end()) {
                it = order.begin();
            }
        }
        
        it = its[1];
        int64_t retVal = 1;
        std::advance(it,1);
        retVal = *it;
        if(it==order.end()) {
            it = order.begin();
        }
        std::advance(it,1);
        retVal *= *it;
        
        return retVal;
    }
}
