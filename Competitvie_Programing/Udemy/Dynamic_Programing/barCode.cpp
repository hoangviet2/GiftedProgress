//#include<bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

int solve(int n, int m,int x, int y, vector<vector<char>> grid){
    int countWhite = 0;
    int countBlack = 0;
    vector<int>black(m+1),white(m+1);
    for(int i=0;i<m;++i){
        countWhite = 0;
        countBlack = 0;
        for(int j=0;j<n;++j){
            if(grid[j][i] == '.'){
                countWhite++;
            }
            if(grid[j][i] == '#'){
                countBlack++;
            }
        }
        white[i+1] = countWhite;
        black[i+1] = countBlack;
    }
    for(int i=1;i<=m;++i){
        white[i] += white[i-1];
        black[i] += black[i-1];
    }
    vector<int>dp1(m+1,1000000000),dp2(m+1,1000000000);
    dp1[0]=dp2[0]=0;
    for(int i=1;i<=m;++i){
        for(int j=x;j<=y;++j){
            if(i-j >= 0){
                countWhite = black[i]-black[i-j];
                countBlack = white[i]-white[i-j];
                dp1[i] = min(dp1[i],dp2[i-j]+countWhite);
                dp2[i] = min(dp2[i],dp1[i-j]+countBlack);
            }
        }
    }
    return min(dp1[m],dp2[m]);
}