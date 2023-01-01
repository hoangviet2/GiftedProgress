// 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    deque<int> ood,even;
    int n;
    cin>>n;
    for(int i=2;i<=n;++i){
        if(i%2 == 0){
            even.push_back(i);
        }else{
            ood.push_back(i);
        }
    }
    int evens = even.back();
    int oods = ood.back();
    even.pop_back();
    ood.pop_back();
    while(!even.empty()){
        evens += even.back();
        cout<<evens-even.back()<<" "<<even.back()<<"\n";
        if(evens%2){
            evens = (evens+1)/2;
        }else{
            evens /= 2;
        }
        even.pop_back();
    }
    while(!ood.empty()){
        oods += ood.back();
        cout<<oods-ood.back()<<" "<<ood.back()<<"\n";
        if(oods%2){
            oods = (oods+1)/2;
        }else{
            oods /= 2;
        }
        ood.pop_back();
    }
    //cout<<oods<<" "<<evens<<"\n";
    int ans = oods + evens;
    cout<<oods<<" "<<evens<<"\n";
    if(ans%2){
        ans = (ans+1)/2;
    }else{
        ans /= 2;
    }
    ans += 1;
    if(ans%2){
        ans = (ans+1)/2;
    }else{
        ans /= 2;
    }
    cout<<ans<<" "<<1<<"\n";
    cout<<ans<<"\n";
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}