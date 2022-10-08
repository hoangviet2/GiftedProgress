#include <bits/stdc++.h>
using namespace std;
int start,last;

bool slove(int idx,int n,int cur,vector<bool>& used,vector<pair<int,int> >& domi){
    // basecase;
    if(idx == n){
        return cur == last;
    }
    // recursion case
    for(int i=0;i<domi.size();i++){
        if(used[i]) continue;
        used[i] = true;
        if(cur == domi[i].first && slove(idx+1,n,domi[i].second,used,domi)){
            return true;
        }
        if(cur == domi[i].second && slove(idx+1,n,domi[i].first,used,domi)){
            return true;
        }
        // backtracking
        used[i] = false;
    }
    return false;
}

int main(){
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
    int n,m,left,right;
    while(cin>>n && n){
        cin >> m;
        cin >> left >> start;
        cin >> last >> right;
        vector<pair<int,int> > domi;
        vector<bool> used(m);
        for(int i=0;i<m;i++){
            cin >> left >> right;
            domi.push_back(make_pair(left,right));
        }
        if(slove(0,n,start,used,domi)){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
    }
}