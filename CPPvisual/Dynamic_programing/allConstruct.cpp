#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
map<string,int> memory;
vector<vector<string>> allConstruct(string target, vector<string> wordbank){
    if(target.empty()) return {{}};
    
    int totalCount = 0;

    for(auto word:wordbank){
        if(target.find(word) != std::string::npos){
            size_t found = target.find(word);
            if(found == 0){
                string suffix = targetString.substr(element.length());
                vector<vector<string>> suffixWays = allConstruct(suffix,wordbank);
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