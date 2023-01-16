#include <iostream>
#include <queue>
#include <fstream>
#include <vector>
using namespace std;
ifstream Inp;
ofstream Oup;
int N,K,temp;
vector<int> arr;
void ReplaceArray(vector<int> arr, int N, int K){
    priority_queue<vector<int>> pq;
    pq.push({ N, 0 });
    int mid;
    for (int i = 1; i <= K; i++) {
        vector<int> sub = pq.top();
        pq.pop();
        if (sub[0] % 2 == 1) {
            mid = sub[1] + sub[0] / 2;
            arr[mid] = i;
            pq.push({ sub[0]/2,sub[1] });
            pq.push({ sub[0] / 2,
                        (mid + 1) });
        }
        else {
            if (i % 2 == 1) {
                mid = sub[1] + sub[0] / 2;
                arr[mid - 1] = i;
                pq.push({ sub[0] / 2 - 1, sub[1] });
                pq.push({ sub[0] / 2, mid });
            }
            else {
                mid = sub[1] + sub[0] / 2;
                arr[mid - 1] = i;
                pq.push({sub[0] / 2,sub[1] });
                pq.push({ sub[0] / 2 - 1,(mid + 1) });
            }
        }
    }
    for (int i = 0; i < N; i++)
        Oup << arr[i] << " ";
}
void Input(){
    Inp>>N;
    for(int i=0;i<N;++i){
        Inp>>temp;
        arr.push_back(temp);
    }
    Inp>>K;
    return;
}
int main(){
    Inp.open("bai5.inp");
    Oup.open("bai5.out");
    Input();
    ReplaceArray(arr, N, K);
    Inp.close();
    Oup.close();
}
