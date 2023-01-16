//
//  BitmaskDP.hpp
//  DynamicProgramming
//
//  Created by Hoang Viet on 14/11/2021.
//
//  ref: https://usaco.guide/CPH.pdf#page=112
#ifndef BitmaskDP_hpp
#define BitmaskDP_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
struct OptimalSelectionInput{
    vector<vector<int>> price;
    OptimalSelectionInput(int days,int products){
        for(int i=0;i<products;++i){
            vector<int> temp;
            for(int j=0;j<products;++j){
                int prices;
                cin>>prices;
                temp.push_back(prices);
            }
            price.push_back(temp);
        }
    }
};
using namespace std;
class BitMask{
public:
    void OptimalSelection();
};
#endif /* BitmaskDP_hpp */
