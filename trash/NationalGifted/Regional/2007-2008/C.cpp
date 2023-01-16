/**
    +     +        +
     +    +      +
      +   +    +
       +  +  +
  + + + + + + + + + 
       +  +  +
      +   +    +
     +    +      +
    +     +        +
                                    
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <algorithm>
using namespace std;
double inf = stod("inf");

vector<int> arr;
vector<vector<double>> dp;

int C;
int maxH = INT_MIN;
double F(int preStation, int p) {
    double ans = inf;
    if (preStation >= 0 && dp[p][preStation] != -1){
        return dp[p][preStation];
    }
    else {
        for (int h = arr[p]; h <= maxH; h++) {
            double thisAns = (h - arr[p]) * (h - arr[p]);
            if (preStation != -1){
                thisAns += C * abs(h - preStation);
            }
            if (p+1 < arr.size()){
                thisAns += F(h, p + 1);
            }
            ans = min(ans, thisAns);
        }
    }
    if (preStation >= 0) dp[p][preStation] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N >> C;
    arr.resize(N);
    for(int i=0;i<arr.size();++i){
        cin>>arr[i];
        maxH = max(maxH,arr[i]);
    }
    dp = vector<vector<double>>(N, vector<double>(maxH+1, -1));
    int ans = F(-1,0);
    cout << ans;
}
