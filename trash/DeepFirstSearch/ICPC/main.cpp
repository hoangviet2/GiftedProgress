#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
int main(){
    ll rows,cols;
    cin>>rows>>cols;
    vector<vector<char>> grid(rows,vector<char>(cols));
    for(ll i=0;i<rows;++i){
        for(ll j=0;j<cols;++j){
            char temp;
            cin>>temp;
            grid[i][j] = temp;
        }
    }
    return 0;
}
