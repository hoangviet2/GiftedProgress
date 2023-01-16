//
//  bai4.cpp
//  Test
//
//  Created by Hoang Viet on 18/10/2021.
//
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
vector<int> arr;
int N,temp;
ifstream Inp;
ofstream Oup;
void Input(){
    Inp>>N;
    for(int i=0;i<N;++i){
        int temp;
        Inp>>temp;
        arr.push_back(temp);
    }
}
// med1
int main(){
    Inp.open("bai4.inp");
    Oup.open("bai4.out");
    Input();
    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        pq.push(arr[i]);
    }
    while (!pq.empty()) {
        Oup<< pq.top() << " ";
        pq.pop();
    }
    Inp.close();
    Oup.close();
    return 0;
}
//med2
int main(){
    Inp.open("bai4.inp");
    Oup.open("bai4.out");
    Input();
    priority_queue<int> pq(arr, arr + N);
    while (!pq.empty()) {
        Oup << pq.top() << " ";
        pq.pop();
    }
    Inp.close();
    Oup.close();
    return 0;
}
