#include<bits/stdc++.h>
#define MAX INT_MAX
#define MIN INT_MIN
#define Max 100
#define INP "INCSEQ.INP","r",stdin
#define OUT "INCSEQ.OUT","w",stdout

using namespace std;
int Trade[Max];
int N;
int a[Max+1];
int L[Max];

void Read_File(){
    cin>>N;
    for(int i=1; i<=N;i++) cin>>a[i];
}

void INCSEQ(){
    int jmax;
    a[0] = MIN;
    a[N+1] = MAX; 
    L[N+1] = 1;
    for(int i = N; i >= 0; i--){
        jmax = N+1;
        for(int j = N+1; j > i; j--){
            if((a[j] > a[i]) && (L[j] > L[jmax]))
                jmax = j;
        }
        L[i] = L[jmax]+1;
        Trade[i] = jmax;
    }
}

void Result(){
    cout<<L[0]-2<<"\n";
    int i = Trade[0];
    while(i != N+1){
        cout<<"a["<<i<<"]="<<a[i]<<"\n";
        i = Trade[i];
    }
}

int main(){
    Read_File();  
    INCSEQ();
    Result();  
}