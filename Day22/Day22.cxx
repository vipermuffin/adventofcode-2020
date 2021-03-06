//
//  Advent of Code 2020 Solutions: Day 22
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/21/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day22.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <unordered_map>
#include <unordered_set>
#include <boost/container_hash/hash.hpp>

using namespace std;
namespace AocDay22 {

    static const std::string InputFileName = "Day22.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        vector<int32_t> p1{},p2{};
        auto itr = input.begin()+1;
        while(itr->size() != 0) {
            p1.push_back(stoi(*itr));
            itr++;
        }
        itr+=2;
        while(itr != input.end() && itr->size() != 0) {
            p2.push_back(stoi(*itr));
            itr++;
        }
		return to_string(playGame(p1, p2));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
        vector<int32_t> p1{},p2{};
        auto itr = input.begin()+1;
        while(itr->size() != 0) {
            p1.push_back(stoi(*itr));
            itr++;
        }
        itr+=2;
        while(itr != input.end() && itr->size() != 0) {
            p2.push_back(stoi(*itr));
            itr++;
        }
        unordered_map<size_t,std::pair<int64_t,bool>> cache{};
        return to_string(playGame2(p1, p2, cache).first);
    }
    
    uint32_t calcScore(const std::vector<int32_t>& deck) {
        uint32_t score = 0;
        auto itr = deck.rbegin();
        for(int i = 1; i <= deck.size();i++) {
            score += i**itr++;
        }
        return score;
    }
    
    uint32_t playGame(std::vector<int32_t> p1, std::vector<int32_t> p2) {
        while(p1.size() > 0 && p2.size() > 0) {
            std::rotate(p1.begin(), p1.begin()+1, p1.end());
            std::rotate(p2.begin(), p2.begin()+1, p2.end());
            auto& winner = p1.back() > p2.back() ? p1 : p2;
            auto& loser = p1.back() > p2.back() ? p2 : p1;
            winner.push_back(loser.back());
            loser.pop_back();
        }
        auto& winner = p1.size() > 0 ? p1 : p2;
        auto score = calcScore(winner);
        return score;
    }

    
    std::pair<int64_t,bool> playGame2(std::vector<int32_t>& p1, std::vector<int32_t>& p2, std::unordered_map<size_t,std::pair<int64_t,bool>>& cache) {
        
        auto sz = p1.size()+p2.size();
        p1.reserve(sz);
        p2.reserve(sz);
        
        unordered_set<std::size_t> scores;
        int64_t score{0};
        bool p1Win{true};
        while(p1.size() > 0 && p2.size() > 0 && score == 0) {
            auto dh{p1};
            dh.reserve(p1.size()+p2.size()+1);
            dh.push_back(222);
            for(const auto& i : p2) {
                dh.push_back(i);
            }
            size_t deck_hash = boost::hash_value(dh);
            if(scores.count(deck_hash) > 0) {
                for(const auto& i : scores) {
                    cache[i] = {-222,true};
                }
                return {-222,true};
            } else {
                scores.insert(deck_hash);
                std::rotate(p1.begin(), p1.begin()+1, p1.end());
                std::rotate(p2.begin(), p2.begin()+1, p2.end());
                auto* winner = p1.back() > p2.back() ? &p1 : &p2;
                auto* loser = p1.back() > p2.back() ? &p2 : &p1;
                if(p1.back() <= p1.size()-1 && p2.back() <= p2.size()-1) {
                    vector<int32_t> p1cpy{p1.begin(),p1.begin()+static_cast<size_t>(p1.back())};
                    vector<int32_t> p2cpy{p2.begin(),p2.begin()+static_cast<size_t>(p2.back())};
                    if(p1cpy.size() > 0 && p2cpy.size() > 0) {
                        auto result = playGame2(p1cpy, p2cpy, cache);
                        winner = result.second ? &p1 : &p2;
                        loser = result.second ? &p2  : &p1;
                    } else {
                        winner = p1cpy.size() > 0 ? &p1 : &p2;
                        loser = p1cpy.size() > 0 ? &p2  : &p1;
                    }
                    
                }
                winner->push_back(loser->back());
                loser->pop_back();
            }
        }
        
        auto& winner = p1.size() > 0 ? p1 : p2;
        p1Win = p1.size() > 0 ? true : false;
        score = calcScore(winner);
        auto result = make_pair(score, p1Win);
        return result;
    }
}
