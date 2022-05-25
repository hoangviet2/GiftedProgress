#include<bits/stdc++.h>
using namespace std;
ifstream fin("22.INP");
ofstream fout("22.OUT");

int n,s=0;
vector<int> a;

void Input(){
    //first line: n
    //second line: the array
    int number;
    fin >> n;
    for(int i=0;i<n;i++){
        fin >> number;
        s+=number;
        a.emplace_back(number);
    }
}

bool Check(int s){
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

int Main_process(){
    int another_s=s/2;
    while(true){
        if(Check(another_s)==true){
            break;
        }
        another_s--;
    }
    return another_s;
}

int main()
{
    Input();
    int answer=Main_process();
    fout << answer << " " << s-answer;
    return 0;
}