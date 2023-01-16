//
//  bai10.cpp
//  Test
//
//  Created by Hoang Viet on 18/10/2021.
//

// C++ Program to implement the
// above approach

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <fstream>

using namespace std;
ifstream Inp;
ofstream Oup;
int N,tempfirst,tempsecond;
vector<pair<int, int>> ranges;
int find_maximum_jobs(int N,vector<pair<int,int>>ranges){
    priority_queue<int,vector<int>,greater<int>> queue;
    sort(ranges.begin(), ranges.end());
    int min_day = ranges[0].first;
    int max_day = 0;
    for (int i = 0; i < N; i++)
        max_day
            = max(max_day,
                ranges[i].second);

    int index = 0, count_jobs = 0;

    for (int i = min_day; i <= max_day; i++) {
        while (index < ranges.size()&& ranges[index].first <= i) {
            queue.push(ranges[index].second);
            index++;
        }
        while (!queue.empty()
            && queue.top() < i)
            queue.pop();
        if (queue.empty())
            continue;
        count_jobs++;
        queue.pop();
    }
    return count_jobs;
}
void Input(){
    Inp>>N;
    for(int i=0;i<N;++i){
        Inp>>tempfirst;
        Inp>>tempsecond;
        ranges.push_back(make_pair(tempfirst, tempsecond));
    }
    return;
}
int main(){
    Inp.open("bai10.inp");
    Oup.open("bai10.out");
    Input();
    Oup << find_maximum_jobs(N, ranges);
    Inp.close();
    Oup.close();
}

