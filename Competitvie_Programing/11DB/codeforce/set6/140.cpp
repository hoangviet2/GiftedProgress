#include <bits/stdc++.h>
using namespace std;

void slove(vector<int> &a){
    int n = a.size();
    for(int i=0;i<n;++i){
        cout<<a[i];
    }
    cout<<"\n";
    while(next_permutation(a.begin(),a.end())){
        for(int i=0;i<n;++i){
            cout<<a[i];
        }
        cout<<"\n";
    }
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    //freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a;
    int temp;
    while(cin>>temp){
        //cout<<temp<<"\n";
        a.push_back(temp);
    }
    slove(a);
    return 0;
}