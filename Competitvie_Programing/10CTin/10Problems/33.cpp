#include<bits/stdc++.h>
using namespace std;
ifstream fin("33.INP");
ofstream fout("33.OUT");

string a,b;//a_reversed
vector<vector<int>> F;
int answer;

void Input(){
    //first line: string a
    //second line: string b
    fin >> a;
    fin >> b;
    F.resize(b.size());
    for(auto &i:F){
        i.resize(a.size());
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
    for(int i=1;i<a.size();i++){
        if(b[0]==a[i]){
            F[0][i]=1;
        }
        else{
            F[0][i]=F[0][i-1];
        }
    }
    for(int i=1;i<b.size();i++){
        if(a[0]==b[i]){
            F[i][0]=1;
        }
        else{
            F[i][0]=F[i-1][0];
        }
    }
    //iteration
    for(int i=1;i<b.size();i++){
        for(int j=1;j<a.size();j++){
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
    fout << F[b.size()-1][a.size()-1];
    return 0;
}