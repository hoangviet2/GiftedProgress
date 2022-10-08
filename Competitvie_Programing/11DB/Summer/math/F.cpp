// Bai F kho vkl dcm oivkl
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int k;
    cin>>k;
    int z = 0;
    int d = 1;
    while(z<k){
        ++d;
        int t = d;
        while(t%5==0){
            ++z;
            t /= 5;
        }
    }
    if(z>k){
        cout<<0;
        return;
    }
    cout<<5<<"\n";
    cout<<d<<" "<<d+1<<" "<<d+2<<" "<<d+3<<" "<<d+4<<"\n";
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
    
    return 0;
}