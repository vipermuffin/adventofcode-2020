//
//  Advent of Code 2020 Solutions: Day 25
//
//  https://adventofcode.com/2020
//
//  Created by vipermuffin on 12/26/2020.
//  Copyright © 2020 vipermuffin. All rights reserved.
//
#pragma once
#include <string>
#include <vector>

namespace AocDay25 {
//Function Definitions
    int32_t findLoopSize(int64_t publicKey);
    int32_t findSecretKey(int64_t publicKey, int32_t loopsize);
}
