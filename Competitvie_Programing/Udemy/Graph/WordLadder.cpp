#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> wordList) {
    unordered_set<string> s;
    for(auto str:wordList){
        s.insert(str);
    }
    int ans = 0;
    queue<string> q;
    q.push(beginWord);
    // BFS
    while(!q.empty()){
        ans++;
        vector<string> v;
        int n = q.size();
        for(int i=0;i<n;++i){
            string str = q.front();
            if(str == endWord){
                return ans;
            }
            for(int j=0;j<str.size();++j){
                char ch = str[j];
                cout<<ch<<"\n";
                for(int k=0;k<=26;++k){
                    str[j]=char(97+k);
                    if(s.find(str)!=s.end()){
                        v.push_back(str);
                        s.erase(str);
                    }
                }
                // backtrack
                str[j]=ch;
            }
            q.pop();
        }
        for(auto itr:v)
        {
            q.push(itr);
        }
    }
    return 0;
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> words = {"hot","dot","dog","lot","log","cog"};
    cout<<ladderLength("hit","cog",words);
    return 0;
}