#include <iostream>
#include <string>

using namespace std;

int main(){
    int testCase;
    
    cin>>testCase;
    while(testCase--){
        int n;
        cin>>n;
        string ans = "";
        string line;
        for(int i=0;i<n-2;++i){
            cin>>line;
            if(ans.empty()){
                ans+=line;
            }else{
                if(ans[ans.length()-1]==line[0]){
                    ans+=line[1];
                }else{
                    ans+=line;
                }
            }
        }
        if(ans.length()==n){
            cout<<ans<<"\n";
        }else{
            cout<<ans+"a"<<"\n";
        }
    }
    return 0;
}