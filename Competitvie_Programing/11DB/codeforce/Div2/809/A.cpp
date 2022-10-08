#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;
    cin>>n>>m;
    string s(m,'B');
    int a[n];
    m--;
    for(int i=0;i<n;++i){
        cin>>a[i];
        a[i]--;
    }
    for(int i=0;i<n;++i){
        //cout<<a[i]<<" "<<m-a[i]<<"\n";
        if(s[a[i]] != 'A' && s[m - a[i]] == 'A'){
            //cout<<"one\n";
            s[a[i]] = 'A';
        }else if(s[a[i]] == 'A' && s[m - a[i]] != 'A'){
            //cout<<"two\n";
            s[m-a[i]] = 'A';
        }else{
            if(a[i] <= (m-a[i])){
                s[a[i]] = 'A';
            }else{
                s[m - a[i]] = 'A';
            }
        }
        //cout<<s<<"\n";
    }
    cout<<s<<"\n";
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
        solve();
    }
    return 0;
}