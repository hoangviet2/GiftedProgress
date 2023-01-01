// Compare T-Shirt Sizes
#include <bits/stdc++.h>
using namespace std;
map<char,int> m;
#define ll long long
void solve(){
    string a,b;
    cin>>a>>b;
    
    int acnt = 0;
    int bcnt = 0;
    int mainA = 0;
    int mainB = 0;
    if(a==b){
        cout<<"="<<"\n";
        return;
    }
    for(int i=0;i<a.size();++i){
        if(a[i] == 'X'){
            acnt += 1;
        }else{
            mainA = m[a[i]];
        }
    }
    for(int i=0;i<b.size();++i){
        if(b[i] == 'X'){
            bcnt += 1;
        }else{
            mainB = m[b[i]];
        }
    }
    
    if(mainA>mainB){
        cout<<">\n";
        return;
    }
    if(mainB>mainA){
        cout<<"<\n";
        return;
    }
    if(mainA == 1){
        acnt *= -1;
        bcnt *= -1;
    }
    //cout<<acnt<<" "<<bcnt<<"\n";
    if(acnt<bcnt){
        cout<<"<\n";
    }else{
        cout<<">\n";
    }
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t = 1;
    m['S'] = 1;
    m['M'] = 2;
    m['L'] = 3;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}