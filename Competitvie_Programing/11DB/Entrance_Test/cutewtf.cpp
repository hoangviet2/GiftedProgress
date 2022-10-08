#include <bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define int long long int

using namespace std;
int five = 0;
int two = 0;
int n;
void phantich(int n){
    while(n%2==0){
        two++;
        n/=2;
    }
    while(n%5==0){
        five++;
        n/=5;
    }
}


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        phantich(temp);
    }
    cout<<min(five,two);
    return 0;
}
