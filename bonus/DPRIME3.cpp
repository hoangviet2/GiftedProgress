#include <iostream>
#include <math.h>
#include <fstream>
#include <vector>
typedef long long ll;
using namespace std;
ll N;
vector<bool> Eratosthenes(ll N){
  vector<bool> check(N+1);
  for (ll i = 2; i <= N; i++) {
    check[i] = true;
  }
  for (ll i = 2; i <= N; i++) {
    if (check[i] == true) {
      for (ll j = 2 * i; j <= N; j += i) {
        check[j] = false;
      }
    }
  }
  return check;
}
int main(){
    freopen("DPRIME3.Inp","r",stdin);
    freopen("DPRIME3.Out","w",stdout);
    cin>>N;
    vector<bool> check = Eratosthenes(N);
    if(N<=12) cout<<-1;
    for(ll j=3;j<=N;++j){
        ll z = 4+(j*j);
        if(z<N && check[z]==true){
            cout<<2<<" "<<j<<" "<<z<<"\n";
        }
    }
  return 0;
}
