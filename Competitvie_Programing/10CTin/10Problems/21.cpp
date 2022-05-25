#include<bits/stdc++.h>
using namespace std;
ifstream fin("21.INP");
ofstream fout("21.OUT");

int n,s;
vector<int> a;
vector<vector<bool>> F;

void Input(){
    //first line: n and s
    //second line: the array
    int number;
    fin >> n >> s;
    for(int i=0;i<n;i++){
        fin >> number;
        a.emplace_back(number);
    }
    // F.resize(n);
    // for(auto &i:F){
    //     i.resize(s+1);
    // }
}

bool Main_process(){
    // F[0][a[0]]=true;
    // for(int i=1;i<n;i++){
    //     for(int t=1;t<=s;t++){
    //         if(a[i]==t || F[i-1][t]==true){
    //             F[i][t]=true;
    //             continue;
    //         }
    //         if(a[i]<t){
    //             F[i][t]=F[i-1][t] | F[i-1][t-a[i]];
    //         }
    //     }
    // }
    vector<bool> F1(s+1,0), F2(s+1,0);
    F1[a[0]]=true;
    for(int i=1;i<=s;i++){
        if(F1[i]==true || i==a[1]){
            F2[i]=true;
            continue;
        }
        if(a[1]<i){
            F2[i]=F1[i-a[1]];
        }
    }
    for(int cou=2;cou<n;cou++){
        F1=F2;
        fill(F2.begin(),F2.end()-1,0);
        for(int i=1;i<=s;i++){
            if(F1[i]==true || i==a[cou]){
                F2[i]=true;
                continue;
            }
            if(a[cou]<i){
                F2[i]=F1[i-a[cou]];
            }
        } 
    }
    return *(F2.end()-1);
}

int main()
{
    Input();
    bool answer=Main_process();
    if(answer==true){
        fout << "YES";
    }
    else{
        fout << "NO";
    }
    return 0;
}