#include <bits/stdc++.h>
using namespace std;
const int kk = 1000000007;
int n,tmp1,tmp2;
vector <int> x,y;
int getVal(vector <int>& v){
      int maxVal = -kk;
      int minVal = kk;
      for(int i = 0; i < v.size(); i++){
         minVal = min(v[i], minVal);
         maxVal = max(v[i], maxVal);
      }
      return maxVal - minVal;
}

int solve(vector<int>& arr1, vector<int>& arr2)
{
     vector <int> ret[4];
      int n = arr1.size();
      for(int i = 0; i < n; i++){
         ret[0].push_back(arr1[i] - arr2[i]);
         ret[1].push_back(arr1[i] + arr2[i]);
         ret[2].push_back(-arr1[i] - arr2[i]);
         ret[3].push_back(-arr1[i] + arr2[i]);
      }
      int ans = -kk;
      for(int i = 0; i < 4; i++){
         ans = max(ans, getVal(ret[i]));
      }
      return ans;
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>tmp1>>tmp2;
        x.push_back(tmp1);
        y.push_back(tmp2);
    }

    cout<<solve(x,y);
}