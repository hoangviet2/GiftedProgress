// C++ program for the above approach
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <fstream>

using namespace std;
ifstream Inp;
ofstream Oup;
vector<int> arr;
int N,temp;
void findTriplets(vector<int> ar, int N){
    unordered_map<int, int> mp;

    for (int x = 0; x < N; x++)
        mp[ar[x]]++;
    priority_queue<pair<int, int> > pq;

    for (auto& pa : mp)
        pq.push({ pa.second, pa.first });
    vector<array<int, 3> > ans;

    while (pq.size() >= 3) {
        pair<int, int> ar[3];
        for (int x = 0; x < 3; x++) {
            ar[x] = pq.top();
            pq.pop();
        }
        ans.push_back({ ar[0].second,
                        ar[1].second,
                        ar[2].second });
        for (int x = 0; x < 3; x++) {
            ar[x].first--;
            if (ar[x].first)
                pq.push(ar[x]);
        }
    }
    Oup << "Maximum number of "
        << "possible triples: ";
    Oup << ans.size() << endl;

    for (auto& pa : ans) {
        for (int v : pa)
            Oup << v << " ";
        Oup << endl;
    }
}
void Input(){
    Inp>>N;
    for(int i=0;i<N;++i){
        cin>>temp;
        arr.push_back(temp);
    }
    return;
}
int main(){
    Inp.open("bai9.inp");
    Oup.open("bai9.out");
    Input();
    findTriplets(arr, N);
    Inp.close();
    Oup.close();
    return 0;
}
