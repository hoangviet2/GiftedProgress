#include <bits/stdc++.h>
using namespace std;

map<char,int> alphabet;
void preprocess(){
    alphabet['A']=1;
    alphabet['H']=1;
    alphabet['I']=1;
    alphabet['M']=1;
    alphabet['O']=1;
    alphabet['T']=1;
    alphabet['U']=1;
    alphabet['V']=1;
    alphabet['W']=1;
    alphabet['X']=1;
    alphabet['Y']=1;
}

void solve(){
    string s;
    cin>>s;
    int n = s.size();
    int ans = 0;
    for(int i=0;i<n;++i){
        for(int j=i;j<n;++j){
            if(!alphabet[s[j]]){
                break;
            }
            if(s[j] == s[i]){
                // check palidmore
                int end=j;
                int sum=0;
                for(int k=i;k<(i+j+1)/2;k++){
                    if(s[k] == s[end--]){
                        sum++;
                    }
                }
                if(sum==(j-i+1)/2){
                    ans=max(ans,j-i+1);
                }
            }
        }
    }
    cout<<ans<<"\n";
}

int main(){
//#ifndef ONLINE_JUDGE
//
//    freopen("input.txt", "r", stdin);
//
//    freopen("output.txt", "w", stdout);
//
//#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    preprocess();
    while(t--){
        solve();
    }
    return 0;
}
