#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s1,s2,s3;
const int maxN = 1007;
int memo[maxN][maxN];
int n;
int helper(int index,int memos){
    if(index<0){
        return 0;
    }
    int a = s1[index] - 48;
    int b = s2[index] - 48;
    int c = s3[index] - 48;
    int temp = (a+b+memos)%10;
    int ans = memo[index][temp];
    if(ans != -1){
        return ans;
    }
    ans = n;
    if(c==temp){
        int aftermem;
        if(a+b+memos >= 10){
            aftermem = 1;
        }else{
            aftermem = 0;
        }
        ans = min(helper(index-1,memos)+1,helper(index-1,aftermem));
    }else{
        if((a+b)%10 == c){
            ans = min(helper(index-1,memos)+1,helper(index-1,memos));
        }else{
            return memo[index][temp] = helper(index-1,memos)+1;
        }
    }
    return memo[index][temp] = ans;
}
void solve(){
    
    while(cin>>n){
        memset(memo,-1,sizeof(memo));
        if(n==0){
            return;
        }
        cin>>s1>>s2>>s3;
        cout<<helper(n-1,0)<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    int t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}