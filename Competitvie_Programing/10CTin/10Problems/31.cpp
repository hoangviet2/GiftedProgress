#include<bits/stdc++.h>
using namespace std;
ifstream fin("31.INP");
ofstream fout("31.OUT");

string a,a_rev;//a_reversed
vector<vector<int>> F;
int answer;

void Input(){
    //first line: string a
    fin >> a;
    a_rev=a;
    reverse(a_rev.begin(),a_rev.end());
    F.resize(a.size());
    for(auto &i:F){
        i.resize(a.size());
    }
    answer=a.size();
}

void Main_process(){
    //setup
    if(a[0]==a_rev[0]){
        F[0][0]=1;
    }
    else{
        F[0][0]=0;
    }
    for(int i=1;i<a.size();i++){
        if(a_rev[0]==a[i]){
            F[0][i]=1;
        }
        else{
            F[0][i]=F[0][i-1];
        }
    }
    for(int i=1;i<a.size();i++){
        if(a[0]==a_rev[i]){
            F[i][0]=1;
        }
        else{
            F[i][0]=F[i-1][0];
        }
    }
    //iteration
    for(int i=1;i<a.size();i++){
        for(int j=1;j<a.size();j++){
            if(a_rev[i]==a[j]){
                F[i][j]=F[i-1][j-1]+1;
            }
            else{
                F[i][j]=max(F[i-1][j],F[i][j-1]);
            }
        }
    }
    answer-=F[a.size()-1][a.size()-1];
}

int main(){
    Input();
    Main_process();
    fout << answer;
    return 0;
}