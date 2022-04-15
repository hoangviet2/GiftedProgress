#include <bits/stdc++.h>
using namespace std;
int t,n,m,a[1001],b[1001];
void solve(){
    int sum=0,numOfSmall=0,numOfBig=0,j=0;
    for (int i=0;i<n;i++){
        if (sum+a[i]<=t){
            sum+=a[i];
            numOfSmall++;
        }
        else {
            b[m+j]=a[i];
            j++;
        }
    };
    sort(b,b+m+j);
    sum=0;
    for (int i=0;i<m+j;i++){
        if (sum+b[i]<=t){
            sum+=b[i];
            numOfBig++;
        }
        else{
            break;
        }
    }
    cout<<numOfSmall+numOfBig;
}
int main(){
    freopen("DELIVERY.inp","r",stdin);
    freopen("DELIVERY.out","w",stdout);
    cin>>t>>n;
    for (i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>m;
    for (i=0;i<m;i++){
        cin>>b[i];
    }
    solve();
    return 0;
}
