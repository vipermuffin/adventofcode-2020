//
//  Advent of Code 2020 Solutions: Day 20
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/20/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay20 {
//Function Definitions
    class ImageTile {
    public:
        ImageTile() = delete;
        ImageTile(const std::vector<std::string>&);
        ImageTile(const std::vector<std::string>&, const int32_t idVal);
        ImageTile(const ImageTile& copy);
        ~ImageTile() = default;
        bool isPossibleNeighbor(const ImageTile&) const;
        uint8_t neighborLocation(const ImageTile&) const;
        void flip();
        void rotateClockwise();
        void displayImage(bool withSides = false) const;
        int32_t countHash() const;
        int32_t countSeaMonsters();
        std::vector<std::string> getImage() const {return _image;};
        int32_t tileId;
        std::string tileName;
        
    private:
        std::vector<std::string> sides;
        std::vector<std::string> _image;
    };
    std::vector<ImageTile> tileFactory(const std::vector<std::string>&);
    int64_t findFourCorners(const std::vector<ImageTile>&);
    ImageTile findArrangement(const std::vector<ImageTile>&);
}
