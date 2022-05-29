#include<bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std;
int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    string s;
    cin>>s;
    s += "$";
    int n = s.size();
    vector<int> p(n),c(n);
    // k = 0
    vector<pair<char,int> > a(n);
    for(int i=0;i<n;++i){
        a[i] = make_pair(s[i],i);
    }
    sort(a.begin(),a.end());

    for(int i=0;i<n;++i){
        p[i] = a[i].second;
    }
    c[p[0]] = 0;
    // marking the point
    // mã hoá kí tự. ví dụ a = 1 thì b = 2 từ đó ta có được thứ tự của các kí tự nhưng nó là dạng số
    for(int i=1;i<n;++i){
        if(a[i].first == a[i-1].first){
            c[p[i]] = c[p[i-1]];
        }else{
            c[p[i]] = c[p[i-1]] + 1;
        }
    }

    int k = 0;
    while((1<<k) <n){ 
        // which is 2^k < n;
        // k --> k+1
        vector<pair<pair<int ,int>,int> > a(n);
        for(int i=0;i<n;++i){
            a[i] = make_pair(make_pair(c[i],c[(i + (1<<k)) % n ]),i);
        }
        sort(a.begin(),a.end());

        for(int i=0;i<n;++i){
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        for(int i=1;i<n;++i){
            if(a[i].first == a[i-1].first){
                c[p[i]] = c[p[i-1]];
            }else{
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
        k++;
    }
    for(int i=0;i<n;++i){
        //cout<<p[i]<<" "<<s.substr(p[i],n-p[i])<<"\n";
        cout<<p[i]<<" ";
    }

	return 0;
}