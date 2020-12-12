//
//  Advent of Code 2020 Solutions: Day 11
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/10/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//

#include "Day11.h"
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
#include <sstream>
//#include <thread>
//#include <tuple>
#include <unordered_map>
//#include <unordered_set>


using namespace std;
namespace AocDay11 {

    static const std::string InputFileName = "Day11.txt";
    std::string solvea() {
        auto input = parseFileForLines(InputFileName);
        auto s = convertMapToString(input);
        auto previousS{s};
        do {
            std::swap(s,previousS);
            performSeating(input);
            s = convertMapToString(input);
        }while(s!=previousS);
        auto x = std::count(s.begin(),s.end(),'#');
        return to_string(x);
    }

    std::string solveb() {
        //6743 too high
        auto input = parseFileForLines(InputFileName);
//        unordered_map<string, int32_t> arrangements{};
//         auto s = convertMapToString(input);
//        arrangements[s]++;
//        do {
//            performSeating(input);
//            s = convertMapToString(input);
//        }while(++arrangements[s] != 1);
//        auto x = std::count(s.begin(),s.end(),'#');
        auto s = convertMapToString(input);
        auto previousS{s};
//        arrangements[s]++;
        do {
            std::swap(s,previousS);
            performSeating2(input);
            s = convertMapToString(input);
        }while(s!=previousS);
        auto x = std::count(s.begin(),s.end(),'#');
		return to_string(x);
    }
    
    int32_t adjacentOccupiedRowCount(const std::string& seating,int row, int col, int rowsize) {
        int32_t occupied{0};
        int32_t index = row*rowsize+col;
        int32_t indexMin = row*rowsize;
        int32_t indexMax = indexMin+rowsize-1;
        //Check left in row
        index--;
        while(index>indexMin && seating[index] == '.') {
            index--;
        }
        if(index >= indexMin ) {
            occupied += seating[index] == '#' ? 1 : 0;
        }
        
        //Check right in row
        index = row*rowsize+col+1;
        while(index<indexMax && seating[index] == '.') {
            index++;
        }
        if(index <= indexMax) {
            occupied += seating[index] == '#' ? 1 : 0;
        }
        //Check up in col
        index = row*rowsize+col-rowsize;
        while(index >=0 && seating[index] == '.') {
            index-=rowsize;
        }
        if(index >= 0 && index < seating.size()) {
            occupied += seating[index] == '#' ? 1 : 0;
        }
        //Check down in col
        index = row*rowsize+col+rowsize;
        while(index < seating.size() && seating[index] == '.') {
            index+=rowsize;
        }
        if(index >= 0 && index < seating.size()) {
            occupied += seating[index] == '#' ? 1 : 0;
        }
        //Check left and up...
        index = (row-1)*rowsize+(col-1);
        indexMin -= rowsize;
        while(indexMin >= 0 && index>=indexMin && seating[index] == '.') {
            index -= rowsize;
            index--;
            indexMin -= rowsize;
        }
        if(indexMin >= 0 && index >= indexMin && index < seating.size()) {
            occupied += seating[index] == '#' ? 1 : 0;
        }
        //Check right and up
        index = (row-1)*rowsize+(col+1);
        indexMax -= rowsize;
        while(indexMax > 0 && index<=indexMax && seating[index] == '.') {
            index -= rowsize;
            index++;
            indexMax -= rowsize;
        }
        if(index >= 0 && index < seating.size() && index<=indexMax ) {
            occupied += seating[index] == '#' ? 1 : 0;
        }
        //Check left and down
        index = (row+1)*rowsize+(col-1);
        indexMin = (row+1)*rowsize;
        while(indexMin >= 0 && index>=indexMin && seating[index] == '.') {
            index += rowsize-1;
            indexMin += rowsize;
        }
        if(index >= 0 && index >= indexMin && index < seating.size()) {
            occupied += seating[index] == '#' ? 1 : 0;
        }
        //Check right and down...
        index = (row+1)*rowsize+(col+1);
        indexMax = (row+1)*rowsize+rowsize-1;
        while(indexMax < seating.size() && index<=indexMax && seating[index] == '.') {
            index += rowsize+1;
            indexMax += rowsize;
        }
        if(index >= 0 && index <= indexMax && index < seating.size()) {
            occupied += seating[index] == '#' ? 1 : 0;
        }
        
        return occupied;
    }
    
    void performSeating(std::vector<std::string>& map) {
        vector<string> copy{map};
        vector<string> columns{};
        stringstream ss{};
        for(int i = 0; i < map.front().size(); i++) {
            ss = stringstream{};
            for(int j = 0; j < map.size();j++) {
                ss << map[j][i];
            }
            columns.push_back(ss.str());
        }
        
        for(int row = 0; row < map.size(); row++) {
            for(int col = 0; col < map[row].size(); col++) {
                int32_t x = 0;
                
                if( row > 0) {
                    x += map[row-1][col] == '#' ? 1 : 0;
                    if(col > 0) {
                        x += map[row-1][col-1] == '#' ? 1 : 0;
                    }
                    if(col < map[row].size()-1) {
                        x += map[row-1][col+1] == '#' ? 1 : 0;
                    }
                }
                if( row < map.size()-1) {
                    x += map[row+1][col] == '#' ? 1 : 0;
                    if(col > 0) {
                        x += map[row+1][col-1] == '#' ? 1 : 0;
                    }
                    if(col < map[row].size()-1) {
                        x += map[row+1][col+1] == '#' ? 1 : 0;
                    }
                }
                if( col > 0) {
                    x += map[row][col-1] == '#' ? 1 : 0;
                }
                if( col < map[row].size()-1) {
                    x += map[row][col+1] == '#' ? 1 : 0;
                }
                
                switch (map[row][col]) {
                    case '.':
                        //do nothing
                        break;
                    case 'L':
                        if(x==0) {
                            copy[row][col] = '#';
                        }
                        break;
                        
                    case '#':
                        if(x>=4) {
                            copy[row][col] = 'L';
                        }
                        break;
                        
                    default:
                        break;
                }
            }
        }
        std::swap(map, copy);
    }
    
    void performSeating2(std::vector<std::string>& map) {
        vector<string> copy{map};
        auto s = convertMapToString(map);
        
        for(int row = 0; row < map.size(); row++) {
            for(int col = 0; col < map[row].size(); col++) {
                int32_t x = adjacentOccupiedRowCount(s, row, col, map[row].size());
                
                switch (map[row][col]) {
                    case '.':
                        //do nothing
                        break;
                    case 'L':
                        if(x==0) {
                            copy[row][col] = '#';
                        }
                        break;
                        
                    case '#':
                        if(x>=5) {
                            copy[row][col] = 'L';
                        }
                        break;
                        
                    default:
                        break;
                }
            }
        }
        std::swap(map, copy);
    }
    
    std::string convertMapToString(const std::vector<std::string>& map) {
        stringstream ss{};
        for(const auto& line : map) {
            ss << line;
        }
        return ss.str();
    }

}
