#include "data.hpp"
void Hemwork::task37(){
    int n;
    int temp;
    cin>>n;
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for(int i=0;i<n;++i){
        cin>>temp;
        maxi = max(maxi, temp);
        mini = min(mini, temp);
    }
    cout<<maxi<<" "<<mini;
    return;
}
void Hemwork::task38(){
    int n;
    int temp;
    cin>>n;
    int maxi = INT_MIN;
    int maxPos = 0;
    for(int i=0;i<n;++i){
        cin>>temp;
        maxi = max(maxi, temp);
        if (maxi == temp) {
            maxPos = i+1;
        }
    }
    cout<<maxPos;
    return;
}
void Hemwork::task39(){
    int n,temp;
    int total = 0;
    float average;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>temp;
        total+=temp;
    }
    average = total/n;
    cout<<setprecision(2)<<fixed<<average;
    return;
}
void Hemwork::task40(){
    int n,temp;
    bool isVaild = false;
    vector<int> a;
    int total = 0;
    float average;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>temp;
        total+=temp;
        a.push_back(temp);
    }
    average = total/n;
    for(int i=0;i<n;++i){
        if(float(a[i])>average){
            isVaild = true;
            cout<<i+1<<" ";
        }
    }
    if(isVaild == false){
        cout<<"Not found";
    }
    return;
}
void Hemwork::task41(){
    int n,temp;
    cin>>n;
    return;
}