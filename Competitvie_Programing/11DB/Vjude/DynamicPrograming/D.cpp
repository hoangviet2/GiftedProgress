#include <bits/stdc++.h>

using namespace std;

int dp[5001];

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    string s;
    while(cin>>s){
        if(s == "0"){
            continue;
        }
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for(int i = 1;i<s.size();++i){
            if(s[i] == '0'){
				if(i == 1){
					dp[i] = dp[i-1];
                }else{
					dp[i] = dp[i-2];
                }
			}
			else{
				if((s[i-1] == '1' && s[i] <= '9') || (s[i-1] == '2' && s[i]<='6')){
					if(i != 1){
						dp[i] = dp[i-1] + dp[i-2];
                    }else{
						dp[i] = 2;
                    }
				}else{
					dp[i] = dp[i-1];
                }
			}      
        }
        cout<<dp[s.size()-1]<<"\n";
    }
}
