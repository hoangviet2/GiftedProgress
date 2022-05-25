#include <vector>
#include <climits>
#include <iostream>

using namespace std;
int jumps(vector<int> numbers,int n,int i,vector<int> dp){
    //base case
    if(i==n-1){
        return 0;
    }
    if(i>=n){
        return INT_MAX;
    }
    //rec case
    if(dp[i]!=0){
        return dp[i];
    }
    //asume
    int steps = INT_MAX;
    int max_Jump = numbers[i];
    for(int jump = 1;jump<=max_Jump;++jump){
        int nexcell = jump+i;
        int subProblem = jumps(numbers,n,nexcell,dp);
        if(subProblem!=INT_MAX){
            steps = min(steps,subProblem+1);
        }
    }
    return dp[i] = steps;
}
int main(){
    int n;
    cin>>n;
    vector<int> numbers;
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        numbers.push_back(temp);
    }
    vector<int> dp(n,0);
    cout<<jumps(numbers,n,0,dp);
    return 0;
}