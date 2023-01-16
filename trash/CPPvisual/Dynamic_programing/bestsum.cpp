#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int,vector<int>> memory;
vector<int> bestSumMemo(vector<int> numbers,int targetNum){
    // Type: Brute force
    // Time = o(n^m)
    // n = targetNum
    // m = numbers.size()
    // Space = O(m^2)
    if(memory.find(targetNum)!=memory.end()){
        return memory.find(targetNum)->second;
    }
    
    if(targetNum==0) return {0};
    if(targetNum<0) return {};
    vector<int> shortest = {};
    for(auto number:numbers){
        int remainder = targetNum - number;
        vector<int> remainderCombination = bestSumMemo(numbers,remainder);
        if(!remainderCombination.empty()){
            remainderCombination.push_back(number);
            if(shortest.empty() ||shortest.size()>remainderCombination.size()){
                shortest = remainderCombination;
            }
        }
    }
    memory[targetNum] = shortest;
    return shortest;
}
int main(){
    vector<int> ans = bestSumMemo({1,2,5,25},100);
    ans.erase(ans.begin(),ans.begin()+1);
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<endl;
    }
    return 0;
}