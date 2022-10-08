#include <bits/stdc++.h>

using namespace std;
int solve(int target){

    int n = ceil((-1.0 + sqrt(1 + 8.0 * target)) / 2);

    int sum = n * (n + 1) / 2;

    if (sum == target){
        return n;
    }
    int diff = sum - target;

    if (diff%2==0){
        return n;
    }
    else{
        if(n%2 == 1){
            return n + 2;
        }else{
            return n + 1;
        }
        //return n + ((n & 1) ? 2 : 1);
    }
}

int main(){
#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        cout << solve(abs(n))<<"\n";
    }

    return 0;
}