#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, sum, diff;
    long long int mul;
    double div;
    cout<<"Nhap a, b: ";
    cin>>a>>b;
    sum = a+b;
    cout<<a<<" + "<<b<<" = "<<sum<<"\n";
    diff = a-b;
    cout<<a<<" - "<<b<<" = "<<diff<<"\n";
    mul = a*b;
    cout<<a<<" * "<<b<<" = "<<mul<<"\n";
    if(b == 0){
        cout<<"Đâu có chia dc au\n";
    }else{
        div = a/b;
        //cout<<setprecision(10)<<fixed;
        cout<<a<<" / "<<b<<" = "<<div<<"\n";
    }
    return 0;
}