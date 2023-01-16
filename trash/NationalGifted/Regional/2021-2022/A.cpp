//#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <stdlib.h>
using namespace std;

struct myans{
    int diff;
    int size;
};

vector<int> checker(vector<int>);
vector<int> readata();
vector<int> sortedInt(vector<int>,bool);
myans minimumDiff(vector<int>);
int helper(vector<int>,int);
int findways(vector<int>,int);

int main(){
    //genExample();
    //freopen("input.INP", "r", stdin);
    //freopen("output.OUT", "w", stdout);
    vector<int> numbers = readata();
    if(numbers.size()==0){
        cout<<0;
        return 0;
    }else if(numbers.size() == 2){
        cout<<abs(numbers[0]-numbers[1])<<" "<<1;
        return 0;
    }
    numbers = sortedInt(numbers,true);
    myans min = minimumDiff(numbers);
    cout<<min.diff<<" "<<findways(numbers, min.diff)/min.size<<"\n";
    return 0;
}

vector<int> checker(vector<int> example){
    for(int i=0;i<example.size();++i){
        example[i] = 30;
    }
    return example;
}

vector<int> readata(){
    int n;
    cin>>n;
    vector<int> ans;
    for(int i=0;i<n;++i){
        int temp;
        cin>>temp;
        ans.push_back(temp);
    }
    return ans;
}

vector<int> sortedInt(vector<int>nums,bool isGreater = true){
    if(isGreater){
        sort(nums.begin(),nums.end(),greater<int>());
    }else{
        sort(nums.begin(),nums.end());
    }
    return nums;
}

// find the minimum
myans minimumDiff(vector<int> numbers){
    int sizes = 1;
    int a = numbers[0];
    int b = numbers[1];
    myans ans;
    for(int i=2;i<numbers.size();++i){
        if(a>b){
            b+=numbers[i];
        }else{
            a+=numbers[i];
            ++sizes;
        }
    }
    ans.size = sizes;
    ans.diff = abs(a-b);
    return ans;
}

// recursion play
int helper(vector<int> nums, int ignoreind){
    int a = nums[ignoreind];
    int b = 0;
    for(int i=0 ;i<nums.size();++i){
        if(i!=ignoreind){
            if(a<b){
                a+=nums[i];
            }else{
                b+=nums[i];
            }
        }
    }
    return abs(a-b);
}

// find ways (do anything except the last)
int findways(vector<int> nums,int target){
    int ans = 1;
    for(int i = 1;i<nums.size();++i){
        if(helper(nums, i)==target){
            ++ans;
        }
    }
    return ans;
}
