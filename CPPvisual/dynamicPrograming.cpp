#include <iostream>
#include <vector>
using namespace std;
vector<int> bestSum(vector<int> numbers,int targetNum){
    // Type: Brute force
    // Time = o(n^m)
    // n = targetNum
    // m = numbers.size()
    // Space = O(m^2)
    if(targetNum==0) return {0};
    if(targetNum<0) return {};
    vector<int> shortest = {};
    for(auto number:numbers){
        int remainder = targetNum - number;
        vector<int> remainderCombination = bestSum(numbers,remainder);
        if(!remainderCombination.empty()){
            remainderCombination.push_back(number);
            //cout<<shortest.size()<<" : "<<remainderCombination.size()<<endl;
            if(shortest.empty() ||shortest.size()>remainderCombination.size()){
                shortest = remainderCombination;
            }
        }
    }
    return shortest;
}
vector<int> bestSumMemo(vector<int> numbers,int targetNum,vector<vector<int>> memory){
    // Type: Brute force
    // Time = o(n^m)
    // n = targetNum
    // m = numbers.size()
    // Space = O(m^2)
    if(!memory[targetNum].empty()) return memory[targetNum];
    if(targetNum==0) return {0};
    if(targetNum<0) return {};
    vector<int> shortest = {};
    for(auto number:numbers){
        int remainder = targetNum - number;
        vector<int> remainderCombination = bestSumMemo(numbers,remainder,memory);
        if(!remainderCombination.empty()){
            remainderCombination.push_back(number);
            //cout<<shortest.size()<<" : "<<remainderCombination.size()<<endl;
            if(shortest.empty() ||shortest.size()>remainderCombination.size()){
                shortest = remainderCombination;
            }
        }
    }
    memory[targetNum] = shortest;
    return shortest;
}
int main(){
    vector<int> blank = {};
    vector<vector<int>> memo(8,blank);
    vector<int> ans = bestSumMemo({5,3,4,7},7,memo);
    ans.erase(ans.begin(),ans.begin()+1);
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<endl;
    }
    return 0;
}