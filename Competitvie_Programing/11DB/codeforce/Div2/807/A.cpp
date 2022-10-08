#include <bits/stdc++.h>
using namespace std;

void print(vector<int> a,int n,int x){
    int l = 0, r = n;
    while(l!=n){
        if(abs(a[l]-a[r])<x){
            cout<<"NO\n";
            return;
        }
        ++l;
        ++r;
    }
    cout<<"YES\n";
    return;
}

void slove(){
    int n,x;
    cin>>n>>x;
    vector<int> a(2*n);
    for(int i=0;i<2*n;++i){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    print(a,n,x);
    return;
}

int main(){
#ifndef ONLINE_JUDGE

    //freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    int t;
    cin>>t;
    while(t--){
        slove();
    }
    return 0;
}