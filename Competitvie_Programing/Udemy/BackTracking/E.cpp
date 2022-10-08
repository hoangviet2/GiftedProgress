// https://codeforces.com/contest/1692/problem/E
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int testcase;
    cin>>testcase;
    while(testcase--){
        int n,s;
        cin>>n>>s;
        int a[n];
        int sum = 0;
        for(int i=0;i<n;++i){
            cin>>a[i];
            sum+=a[i];
        }
        if(s == sum){
            cout<<0<<"\n";
        }else if(sum<s){
            cout<<-1<<"\n";
        }
        else{
            int start = 0;
            int end = n-1;
            int ended = sum-s;
            int steps = 0;
            while(ended != 0){
                if(a[start] == 0 && a[end] == 0){
                    ++steps;
                    ++start;
                    ++end;
                }else if(a[start] == 1 && a[end] == 0){
                    ++steps;
                    ++start;
                    ended--;
                }
                else if(a[start] == 1 && a[end] == 0){
                    ++steps;
                    ++end;
                    ended--;
                }else{
                    ++steps;
                    ++start;
                    ++end;
                    ended--;
                }
            }
            cout<<steps<<"\n";
        }
        
    }
	return 0;
}

