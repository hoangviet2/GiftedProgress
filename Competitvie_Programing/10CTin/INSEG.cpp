// Longest increasing Subquence
#include <iostream>
#include <vector>

using namespace std;
int lis(vector<int> numbers){
    int ans = 1;
    vector<int> dp(numbers.size()+1,1);
    for(int i=1;i<numbers.size();++i){
        for(int j=0;j<i;++j){
            if(numbers[i]>numbers[j]){
                dp[i] = max(dp[i],dp[j]+1);
                ans = max(ans,dp[i]);
            }
        }
    }
    return ans;
}
int main(){
    vector<int> numbers;
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        numbers.push_back(temp);
    }
    cout<<lis(numbers);
    return 0;
}