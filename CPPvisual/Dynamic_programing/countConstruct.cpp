#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
map<string,int> memory;
int countConstruct(string target, vector<string> wordbank){
    if(memory.find(target)!=memory.end()){
        cout<<memory.size()<<endl;
        return memory[target];
    }
    if(target.empty()) return 1;
    
    int totalCount = 0;

    for(auto word:wordbank){
        if(target.find(word) != std::string::npos){
            size_t found = target.find(word);
            if(found == 0){
                int numWayForRest = countConstruct(target.substr(word.length()),wordbank);
                totalCount += numWayForRest;
            }
        }
    }
    memory[target] = totalCount;
    return totalCount;
}
int main(){
    map<string,int> memory;
    cout<<"The count number is: "<<countConstruct("abcdef",{"abc","ab","cd","def","abcd","cdef"});
    return 0;
}