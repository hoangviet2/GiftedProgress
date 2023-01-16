// C++ program for the above approach

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;
ifstream Inp;
ofstream Oup;
int N,W,K,temp;
vector<int> profits,capital;
int maximizedCapital(int K, int W,vector<int>& profits,vector<int>& capital){
    priority_queue<int> pq;
    vector<pair<int, int> > v;
    for (int i = 0;
        i < capital.size(); i++) {
        v.push_back({ capital[i], i });
    }
    sort(v.begin(), v.end());

    int j = 0;

    while (K) {
        while ((j < (int)capital.size()) && (v[j].first <= W)) {
            pq.push(profits[v[j].second]);
            j++;
        }
        if (!pq.empty()) {
            W = W + pq.top();
            pq.pop();
        }
        K--;
    }
    return W;
}
void Input(){
    Inp>>N;
    Inp>>W;
    Inp>>K;
    for(int i=0;i<N;++i){
        profits.push_back(temp);
    }
    for(int i=0;i<N;++i){
        capital.push_back(temp);
    }
}
int main(){
    Inp.open("bai3.inp");
    Oup.open("bai3.out");
    Input();
    Oup<< maximizedCapital(K, W, profits, capital);
    Oup.close();
    Inp.close();
    return 0;
}
