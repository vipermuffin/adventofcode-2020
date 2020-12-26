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
//#include <regex>
//#include <set>
//#include <sstream>
//#include <thread>
//#include <tuple>
//#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay23 {
    constexpr int32_t N = 1000000;
    
    static const std::string InputFileName = "Day23.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        list<int32_t> order{3,1,5,6,7,9,8,2,4};

		return playGame(order, 100);
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        list<int32_t> order{3,1,5,6,7,9,8,2,4};
        for(int i = 10; i <= N; i++ ) {
            order.push_back(i);
        }

        return to_string(playGame2(order, 10000000));
    }

    std::string playGame(std::list<int32_t>& order,int32_t rounds) {
        auto it = order.begin();
        
        auto minVal = *min_element(order.begin(), order.end());
        auto maxVal = *max_element(order.begin(), order.end());
        for(int i = 0; i < rounds; i++) {
//            cout << *it << endl;
            vector<int32_t> x{};
            for(int j = 0; j<3;j++) {
                auto cpy{it};
                cpy++;
                if(cpy==order.end())
                    cpy = order.begin();
                x.push_back(*cpy);
                order.erase(cpy);
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
            auto itr = find(order.begin(),order.end(),destVal);
//            cout << destVal << endl;
//            printVector(x);
            for(const auto val : x) {
                itr = order.insert(++itr, val);
            }
            it++;
            if(it == order.end()) {
                it = order.begin();
            }
//            for(const auto& val : order) {
//                cout << val;
//            }
//            cout << endl;
        }
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
        its.resize(N+1,order.begin());
        
        auto it = order.begin();
        while(it != order.end()) {
            its[*it] = it;
            std::advance(it, 1);
        }
        
        it = order.begin();
        for(int i = 0; i < rounds; i++) {
            vector<int32_t> x{};
            auto cpy = std::next(it);
            for(int j = 0; j < 3;j++) {
                if(cpy == order.end()) {
                    cpy = order.begin();
                }
                x.push_back(*cpy);
                cpy = order.erase(cpy);
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
            if(destVal != *its[destVal]) {
                //Something wrong
                auto itReset = order.begin();
                while(itReset != order.end()) {
                    its[*itReset] = itReset;
                    std::advance(itReset, 1);
                }
                cout << ".";
                itr = std::next(its[destVal]);
            }
            
            for(const auto val : x) {
                its[val] = order.insert(itr, val);
                itr = std::next(its[val]);
            }
            std::advance(it, 1);
            if(it == order.end()) {
                it = order.begin();
            }
        }
        
        it = its[1];
        int64_t retVal = 1;
        cout << *it << ":";
        it++;
        retVal = *it;
        if(it==order.end()) {
            it = order.begin();
        }
//        cout << *it << ":";
        it++;
        retVal *= *it;
//        cout << *it << endl;
        
        return retVal;
    }
}
