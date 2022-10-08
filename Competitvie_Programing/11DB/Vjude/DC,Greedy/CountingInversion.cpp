#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll _mergeSort(ll a[],ll temp[], ll left,ll right);
ll merge(ll a[],ll temp[],ll left,ll mid,ll right);


ll _mergeSort(ll a[],ll temp[],ll left,ll right){
    ll mid, inversion_count = 0;
    if(right>left){
        mid = (left+right)/2;
        inversion_count += _mergeSort(a,temp,left,mid);
        inversion_count += _mergeSort(a,temp,mid+1,right);

        //merge
        inversion_count += merge(a,temp,left,mid+1,right);
    }
    return inversion_count;
}

ll mergeSort(ll a[],ll n){
    //ll n = sizeof(a)/sizeof(a[0]);
    //cout<<"arr size: "<<n<<"\n";
    ll temp[n];
    return _mergeSort(a,temp,0,n-1);
}

ll merge(ll a[],ll temp[],ll left,ll mid,ll right){
    ll i,j,k;
    ll inversion_count = 0;
    i = left; // left path
    j = mid; // right path
    k = left;
    while((i<=mid-1) && (j<=right)){
        if(a[i]<=a[j]){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
            inversion_count = inversion_count + (mid-i);
        }
    }
    while (i <= mid - 1){
        temp[k++] = a[i++];
    }
    while (j <= right){
        temp[k++] = a[j++];
    }
    for (i = left; i <= right; i++){
        a[i] = temp[i];
    }
  
    return inversion_count;
}

void slove(){
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;++i){
        cin>>arr[i];
    }
    // for(ll i=0;i<n;++i){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<"\n";
    cout<<mergeSort(arr,n)<<'\n';
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout<<"Hello world"<<"\n";
    ll t;
    cin>>t;
    //t = 1;
    while(t--){
        //cout<<t<<"\n";
        slove();
    }
    return 0;
}