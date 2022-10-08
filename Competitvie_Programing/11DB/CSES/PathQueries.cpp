#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 2e5+1;

struct Fenwick{
    vector<ll> fn;
    int n;
    void init(int n){
        this->n = n+1;
        fn.resize(this->n);
    }

    void add(int x,int y){
        x++; // 1 based index
        while(x<n){
            fn[x] += y;
            x+= (x&(-x));// last set bit
        }
    }

    ll sum(int x){
        x++;
        ll ans = 0;
        while(x){
            ans += fn[x];
            x -= (x&(-x));
        }
        return ans;
    }

    int sum(int l,int r){
        return sum(r) - sum(l-1);
    }
};

Fenwick ft;

int values[maxN];
int seg[maxN];
int euler[maxN];
vector<int> gr[maxN];
int timer  = 0;
void dfs(int cur,int par){ //euler tour
    seg[cur] = timer++;
    for(auto x:gr[cur]){
        if(x!=par){
            dfs(x,cur);
        }
    }
    euler[cur] = timer-1;
    return;
}

void solve(){
    int n,queries;
    int a,b;
    cin>>n>>queries;
    for(int i=1;i<=n;++i){
        cin>>values[i];
    }
    for(int i=0;i<n-1;++i){
        cin>>a>>b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    dfs(1,0);
    ft.init(maxN);
    for(int i = 1;i<=n;++i){
        ft.add(seg[i],values[i]);
        ft.add(euler[i]+1,-values[i]);
    }

    for(int i=0;i<queries;++i){
        int type, s;
        cin >> type >> s;
		if(type == 1) {
			int x;
            cin >> x;
			ft.add(seg[s], x-values[s]);
			ft.add(euler[s]+1, -(x-values[s])); // increment by 1
			values[s] = x;
		} else {
			cout << ft.sum(seg[s]+2) << '\n';
		}
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
    
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}