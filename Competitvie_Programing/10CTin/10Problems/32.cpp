#include<bits/stdc++.h>
using namespace std;
ifstream fin("32.INP");
ofstream fout("32.OUT");

int m,n;
vector<int> a,b;
vector<vector<int>> F;

void Input(){
    //first line: m and n
    //second line: m alpha cities
    //third line: n beta cities
    //1 pair of cities (a[i] and b[j]) is coalesced when a[i]=b[j]
    //example: m=n=6
    //6 1 3 2 5 4
    //6 4 1 3 5 2
    //pairs of coalesced cities are
    //a[0] & b[0]
    //a[1] & b[2]
    //a[2] & b[3]
    //a[3] & b[5]
    //a[4] & b[4]
    //a[5] & b[1]
    int number;
    fin >> m >> n;
    for(int i=0;i<m;i++){
        fin >> number;
        a.emplace_back(number);
    }
    for(int i=0;i<n;i++){
        fin >> number;
        b.emplace_back(number);
    }
    F.resize(n) ;
    for(auto &i:F){
        i.resize(m);
    }
}

void Main_process(){
    //setup
    if(a[0]==b[0]){
        F[0][0]=1;
    }
    else{
        F[0][0]=0;
    }
    for(int i=1;i<m;i++){
        if(b[0]==a[i]){
            F[0][i]=1;
        }
        else{
            F[0][i]=F[0][i-1];
        }
    }
    for(int i=1;i<n;i++){
        if(b[i]==a[0]){
            F[i][0]=1;
        }
        else{
            F[i][0]=F[i-1][0];
        }
    }
    //iteration
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(b[i]==a[j]){
                F[i][j]=F[i-1][j-1]+1;
            }
            else{
                F[i][j]=max(F[i-1][j],F[i][j-1]);
            }
        }
    }
}

int main(){
    Input();
    Main_process();
    fout << F[n-1][m-1];
    return 0;
}