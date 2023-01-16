//
//  main.cpp
//  Test
//
//  Created by Hoang Viet on 18/10/2021.
//

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <fstream>
using namespace std;
ifstream Inp;
ofstream Oup;
int N,K;
vector<int> speed,efficiency;
void generateArrayofPairs(int n, vector<int>& speed,vector<int>& efficiency,vector<pair<int, int> >& arr){
 
    for (int i = 0; i < n; i++) {
        arr[i] = make_pair(efficiency[i], speed[i]);
    }
 
    sort(arr.rbegin(), arr.rend());
}
int maxPerformance(vector<int>& speed, int K,vector<int>& efficiency)
{
 
    int n = speed.size();
    vector<pair<int, int> > arr(n);
    generateArrayofPairs(n, speed,efficiency, arr);
 
    priority_queue<int,vector<int>,greater<int>> pq;
    int ans = 0;
    int SumOfSpeed = 0;
 
    for (auto& it : arr) {
 
        int efficient = it.first;
        int speed = it.second;
 
        SumOfSpeed += speed;
 
        pq.push(speed);
 
        if (pq.size() > K) {
 
            int temp = pq.top();
            SumOfSpeed -= temp;
            pq.pop();
        }
 
        ans = max(ans, SumOfSpeed * efficient);
    }
    return ans;
}
void Input(){
    Inp>>N;
    for(int i=0;i<N;++i){
        int temp;
        Inp>>temp;
        speed.push_back(temp);
    }
    for(int i=0;i<N;++i){
        int temp;
        Inp>>temp;
        efficiency.push_back(temp);
    }
    Inp>>K;
}
int main1(){
    Inp.open("bai1.inp");
    Oup.open("bai1.out");
    Input();
    Oup << maxPerformance(speed, K, efficiency);
    Inp.close();
    Oup.close();
    return 0;
}
