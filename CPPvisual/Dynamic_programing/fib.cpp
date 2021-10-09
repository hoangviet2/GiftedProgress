#include <iostream>
#include <vector>
using namespace std;
int fibo(int n){
    vector<int> tablefib(n+3,0);
    // tablefib[1] = 1;
    // for(int i=1;i<=n;++i){
    //     tablefib[i+1] += tablefib[i];
    //     tablefib[i+2] += tablefib[i];
    // }
    return tablefib[n];
}
int main(){
    cout<<fibo(50)<<endl;
    return 0;
}