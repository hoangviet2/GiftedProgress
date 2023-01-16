#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
bool canConstruct(string targetString, vector<string> wordbank){
    if(!targetString.empty()) return true;
    for(auto element:wordbank){
        if(targetString.find(element) != std::string::npos){
            size_t found = targetString.find(element);
            if(found==0){
                string suffix = targetString.substr(element.length());
                if(canConstruct(suffix,wordbank) == true){
                    return true;
                }
            }
        }
    }
    return false;
}
map<string,bool> memo;
bool canConstructMemo(string targetString, vector<string> wordbank){
    if(memo.find(targetString) != memo.end()){
        return memo[targetString];
    }
    if(targetString.empty()) return true;

    for(auto element:wordbank){
        if(targetString.find(element) != std::string::npos){
            size_t found = targetString.find(element);
            if(found==0){
                string suffix = targetString.substr(element.length());
                if(canConstructMemo(suffix,wordbank) == true){
                    memo[targetString] = true;
                    return true;
                }
            }
        }
    }
    memo[targetString] = false;
    return false;
}
int main(){
    cout<<canConstructMemo("eeeeeeeeeeeeeeeeeeeeeeeeeef",{"e","ee","eee","eeee","eeeee","eeeeee"});
    return 0;
}