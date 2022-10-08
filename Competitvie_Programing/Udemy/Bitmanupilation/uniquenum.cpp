#include <bits/stdc++.h>

using namespace std;

int uniquenum(vector<int> a){
    int n = a.size();

    int cumculative_xor = 0;

    for(int i=0;i<n;++i){
        //cout<<cumculative_xor<<" ";
        cumculative_xor = cumculative_xor^a[i];
    }
    cout<<"\n";
    return cumculative_xor;
}

void uniquenum2(vector<int> a){
    int n = a.size();

    int cumculative_xor = 0;

    for(int i=0;i<n;++i){
        cout<<cumculative_xor<<" ";
        cumculative_xor = cumculative_xor^a[i];
    }

    // Pos
    int pos = 0;
    int temp = cumculative_xor;
    while((temp&1) == 0){
        pos++;
        temp = temp >> 1;
    }

    int setA = 0;
    int setB = 0;
    int mask = (1<<pos);
    for(int i=0;i<a.size();++i){
        if((a[i]&mask) > 0){
            setA = setA^a[i];
        }else{
            setB = setB^a[i];
        }
    }
    cout<<setA<<" "<<setB;
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    vector<int> a;
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    uniquenum2(a);
    return 0;
}