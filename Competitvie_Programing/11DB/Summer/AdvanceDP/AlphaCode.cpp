#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 5007;
int n;
ll dp[maxN];
string s;
ll helper(int index = 0){
    if(index>n){
        return 0;
    }
    if(index == n){
        return 1;
    }
    ll &ans = dp[index];
    // da bruh
    if(ans != -1){
        return ans;
    }
    
    if(s[index] == '0'){
        return ans = 0;
    }

    ans = helper(index+1);
    if(index+1<n){
        if (s[index] == '1' || s[index] == '2' && s[index+ 1] <= '6') {
			ans += helper(index + 2);
		}
    }

    return ans;
}

void solve(){
    while(cin>>s){
        if(s=="0"){
            return;
        }
        n = s.size();
        memset(dp,-1,sizeof(dp));
        cout<<helper()<<"\n";
    }
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    solve();
    return 0;
}