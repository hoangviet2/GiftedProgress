#include <bits/stdc++.h>
using namespace std;
string s;
vector<vector<int> > indexes(256);

void prepare(){
    cin >> s;
    for(int i=0;i<s.length();i++){
        indexes[s[i]].push_back(i);
    }
    return;
}

void slove(){
    cin >> s;
    int prevIndex = -1;
    int from;
    bool valid = true;
    for(int i=0;i<s.length() && valid;i++){
        // find next smallest index larger than prevIndex
        auto upper = upper_bound(indexes[s[i]].begin(),indexes[s[i]].end(),prevIndex);
        valid = upper != indexes[s[i]].end(); // no larger index
        prevIndex = *upper;
        if(i == 0){
            from = prevIndex;
        }
    }
    if(valid){
        cout<<"Matched "<<from<<" "<<prevIndex<<"\n";
    }else{
        cout<<"Not matched"<<"\n";
    }
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    prepare();
    int queries;
    cin >> queries;
    while(queries--){
        slove();
    }
}