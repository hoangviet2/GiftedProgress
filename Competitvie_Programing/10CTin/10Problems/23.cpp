#include<bits/stdc++.h>
using namespace std;
ifstream fin("23.INP");
ofstream fout("23.OUT");

int n,s_target,s_high,s_low;
vector<int> a,all_cases;
vector<vector<bool>> F;

void Input(){
    //first line: n and sum_target
    // second line: the array
    int number;
    fin >> n >> s_target;
    fin >> number;
    a.emplace_back(number);
    s_high=number;
    s_low=number;
    for(int i=1;i<n;i++){
        fin >> number;
        s_high+=number;
        s_low-=number;
        a.emplace_back(number);
    }
    F.resize(n);
    for(auto &i:F){
        i.resize(-s_low+s_high+1);
    }
}

int index_pos(int x){
    return x-s_low;
}

int index_neg(int x){
    return x+s_low;
}

void Main_process(){
    F[0][index_pos(a[0])]=true;
    F[n-1][index_pos(s_low)]=true;
    F[n-1][index_pos(s_high)]=true;
    for(int i=1;i<n;i++){
        for(int j=index_pos(s_low);j<=index_pos(s_high);j++){
            if(index_neg(j)-a[i]<s_low){
                F[i][j]=F[i-1][index_pos(index_neg(j)+a[i])];
                continue;
            }
            if(index_neg(j)+a[i]>s_high){
                F[i][j]=F[i-1][index_pos(index_neg(j)-a[i])];
                continue;
            }
            F[i][j]=F[i-1][index_pos(index_neg(j)-a[i])] | F[i-1][index_pos(index_neg(j)+a[i])];
        }
    }
}

int main()
{
    Input();
    Main_process();
    if(F[n-1][index_pos(s_target)]==true){
        fout << "YES";
    }
    else{
        fout << "NO";
    }
    return 0;
}