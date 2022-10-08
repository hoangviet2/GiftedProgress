#include<bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;
const int MAXN=505;
int n,ans,a[4]={0,1,2,3};
char p[MAXN][5],s[4]={'s','h','d','c'};
int b[MAXN],d[MAXN];
struct Node{
    int pos,val;
}c[MAXN];

bool cmp1(Node a,Node b){
    return a.val<b.val;
}

bool cmp2(Node a,Node b){
    return a.val>b.val;
}

int get(char ch){
    if(ch>='0'&&ch<='9')return ch-'0';
    if(ch=='A')return 14;
    if(ch=='T')return 10;
    if(ch=='J')return 11;
    if(ch=='Q')return 12;
    if(ch=='K')return 13;
}

void work(int x){
    int rk=0;
    for(int i=0;i<4;i++){
        int tot=0;
        for(int j=0;j<n;j++){
            if(p[j][1]==s[a[i]]){
                c[tot].pos=j;c[tot].val=get(p[j][0]);
                tot++;
            }
        }
        if(x&(1<<i))sort(c,c+tot,cmp1);
        else sort(c,c+tot,cmp2);
        for(int j=0;j<tot;j++){
            b[c[j].pos]=rk++;
        }
    }
    int k=1;
    d[k]=b[0];
    for(int i=1;i<n;i++){
        if(b[i]>d[k])d[++k]=b[i];
        else{
            int l=1,r=k;
            while(l<=r){
                int mid=(l+r)>>1;
                if(b[i]>d[mid])l=mid+1;
                else r=mid-1;
            }
            d[l]=b[i];
        }
    }
    ans=min(ans,n-k);
}

int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    ans=0;
    do{
        for(int i=0;i<(1<<4);i++)work(i);
    }while(next_permutation(a,a+4));
    cout<<ans;
    return 0;
}