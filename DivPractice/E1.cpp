//Question Link: https://codeforces.com/contest/1611/problem/E1
#include <bits/stdc++.h>
typedef std::pair<int,int> pii;
int main()
{
    int t;
    std::cin>>t;
    for(int __=0;__!=t;++__){
        int N,K;
        std::cin>>N>>K;
        std::vector<int> con[N];
        std::queue<pii> niveis;
        int tol[N]={};
        bool visitou[N]={};
        for(int i=0;i!=K;++i){
            int x;
            std::cin>>x;--x;
            niveis.push({x,0});
        }
        for(int i=1;i!=N;++i){
            int a,b;
            std::cin>>a>>b;
            --a;--b;
            con[a].push_back(b);
            con[b].push_back(a);
        }
        while(niveis.size()){
            auto _ = niveis.front();
            niveis.pop();
            if(visitou[_.first])continue;
            visitou[_.first]=true;
            tol[_.first]=_.second;
            for(auto&x:con[_.first]){
                niveis.push({x,_.second+1});
            }
        }
        std::queue<pii> bfs2;
        bfs2.push({0,0});
        bool vis[N]={};
        while(bfs2.size()){
            auto _ = bfs2.front();
            bfs2.pop();
            if(tol[_.first]<=_.second)continue;
            if(vis[_.first])continue;
            vis[_.first]=true;
            if(con[_.first].size()==1&&_.first){
                printf("YES\n");
                goto prox;
            }
            for(auto&x:con[_.first])bfs2.push({x,_.second+1});
        }
        printf("NO\n");
        prox:{}
    }
}
