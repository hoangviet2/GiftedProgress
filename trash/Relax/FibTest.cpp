#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define ll long long
int globalMaxSum;
	int maxSubArray(vector<int> &nums, int n) {
		if (n == 1) return nums[0];
		int currMaxSum = max(nums[n - 1], maxSubArray(nums, n - 1) + nums[n - 1]);
		globalMaxSum = max(globalMaxSum, currMaxSum);
		return currMaxSum;
	}
    int maxSubArray(vector<int> &nums) {
        globalMaxSum = nums[0];
		maxSubArray(nums, nums.size());
        return globalMaxSum;
    }
int main(){
    cout<<"Hi"<<"\n";
    return 0;
}