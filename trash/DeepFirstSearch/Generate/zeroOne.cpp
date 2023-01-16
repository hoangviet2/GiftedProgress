//
//  zeroOne.cpp
//  Generate
//
//  Created by Hoang Viet on 07/11/2021.
//

#include <iostream>
#include <cmath>
#include <vector>

void _to_bin(int num, std::vector<int> * out) {
    if (num / 2)
        _to_bin(num/2, out);
    out->push_back(num % 2);
}

void to_bin(int num, int numDigit) {
    std::vector<int> out;
    _to_bin(num, &out);
    for(int i = 0; i < numDigit - out.size(); ++i)
        std::cout << 0;
    for(int i = 0; i < out.size(); ++i)
        std::cout << out.at(i);
    std::cout << std::endl;
}

void to0101(int numDigit) {
    // all 0
    for(int fist_01_pos = 0; fist_01_pos < numDigit - 1; ++fist_01_pos) {
        int mask = 0;
        mask |= (1 << fist_01_pos);
        for(int second_01_pos = 2 + fist_01_pos; second_01_pos < numDigit - 1; ++second_01_pos) {
            int result = mask;
            result |= (1 << second_01_pos);
            to_bin(result, numDigit);
        }
    }

    // all 1
    for(int fist_01_pos = 0; fist_01_pos < numDigit - 1; ++fist_01_pos) {
        // slow but short code to get all bits set to 1
        int mask = (int)pow(2,numDigit) - 1;
        mask ^= (2 << fist_01_pos);
        for(int second_01_pos = 2 + fist_01_pos; second_01_pos < numDigit - 1; ++second_01_pos) {
            int result = mask;
            result ^= (2 << second_01_pos);
            to_bin(result, numDigit);
        }
    }
}

int main() {
    std::cout << std::endl << "5 digits" << std::endl << std::endl;
    to0101(5);
    std::cout << std::endl << "10 digits" << std::endl << std::endl;
    to0101(10);
    std::cout << std::endl << "15 digits" << std::endl << std::endl;
    to0101(15);
    return 0;
}
