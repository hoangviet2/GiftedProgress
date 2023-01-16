#include <bits/stdc++.h>

using namespace std;

int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        int n;
        cin>>n;
        vector<int> arr;
        for(int i=0;i<n;++i){
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        arr.push_back(0);
        sort(arr.begin(),arr.end());
        cout << (arr[n] - arr[n-1] > 1 ? "NO" : "YES") <<"\n";
    }
    return 0;
}