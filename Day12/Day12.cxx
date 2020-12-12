//
//  Advent of Code 2020 Solutions: Day 12
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/12/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day12.h"
#include "AoCUtils.h"
//Common Libraries
#include <algorithm> //std::sort, find, for_each, max_element, etc
#include <climits>   //INT_MIN, INT_MAX, etc.
#include <functional> //std::function
#include <unordered_map>


using namespace std;
namespace AocDay12 {

    static const std::string InputFileName = "Day12.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
		return to_string(navigatePath(input));
    }

    std::string solveb() {
        auto input = parseFileForLines(InputFileName);
		return to_string(navigatePath(input,true));
    }
    
    int32_t navigatePath(const std::vector<std::string>& input, const bool useWaypoint) {
        int32_t x{0},y{0},sx{0},sy{0};
        string d{"ESWN"};
        unordered_map<char, function<void(int)>> op{
            {'N',[&](int32_t val){y+=val;}},
            {'S',[&](int32_t val){y-=val;}},
            {'E',[&](int32_t val){x+=val;}},
            {'W',[&](int32_t val){x-=val;}},
        };
        
        if(useWaypoint) {
            x=10;y=1;
            op.emplace('L',[&](int32_t val){val/=90;while(val-->0) {std::swap(x,y);x=-x;}});
            op.emplace('R',[&](int32_t val){val/=90;while(val-->0) {std::swap(x,y);y=-y;}});
            op.emplace('F',[&](int32_t val){sx += x*val;sy += y*val;});
        } else {
            op.emplace('L',[&](int32_t val){std::rotate(d.rbegin(),d.rbegin()+(val/90),d.rend());});
            op.emplace('R',[&](int32_t val){std::rotate(d.begin(),d.begin()+(val/90),d.end());});
            op.emplace('F',[&](int32_t val){op[d[0]](val);});
        }
        
        for_each(input.begin(),input.end(),[&op](const string& s){op[s[0]](stoi(string{s.begin()+1,s.end()}));});
        
        if(useWaypoint) {
            std::swap(x,sx);
            std::swap(y,sy);
        }
        return (x > 0 ? x : -x) + (y > 0 ? y : -y);
    }
}
