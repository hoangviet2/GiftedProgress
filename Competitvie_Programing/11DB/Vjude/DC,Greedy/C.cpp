#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > mapple(256);
string s;
void prepare(){
    int n = s.size();
    // lưu các giá trị index của mỗi phần tử của s
    for(int i=0;i<n;++i){
        mapple[s[i]].push_back(i);
    }
}

void slove(){
    string t;
    cin>>t;
    int start;
    int preIndex = -1;
    bool valid = true;
    for(int i=0;i<t.size() && valid;++i){
        auto upper = upper_bound(mapple[t[i]].begin(),mapple[t[i]].end(),preIndex);
        preIndex = *upper;
        valid = (upper != mapple[t[i]].end()); // không có cái nào trong khoảng từ preIndex -> mapple[t[i]]
        if(i==0){
            start = preIndex;
        }
    }
    if(valid){
        cout<<"Matched "<<start<<" "<<preIndex<<"\n";
    }else{
        cout<<"Not matched"<<"\n";
    }
}

int main(){
// #ifndef ONLINE_JUDGE

//     freopen("input.txt", "r", stdin);

//     freopen("output.txt", "w", stdout);

// #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    prepare();
    //cout<<"Hello world"<<"\n";
    int queries;
    cin>>queries;
    while (queries--){
        slove();
    }
    
    return 0;
}