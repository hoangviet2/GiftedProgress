#include <iostream>
#include <vector>
#include <utility>
using namespace std;
vector<int> rowNbr;
vector<int> colNbr;
bool isSafe(pair<int,int> corr,pair<int,int> size){
    return (corr.first>=0) && (corr.first<=size.first-1) && (corr.second>=0) && (corr.second<=size.second-1);
}
void depthFirstSearch(vector<vector<int>> Graph,pair<int,int> node){
    if(isSafe(node,make_pair(Graph.size(),Graph[0].size())) && Graph[node.first][node.second] == 1){
        Graph[node.first][node.second] = 0;
        for(int i=0;i<8;++i){
            depthFirstSearch(Graph,make_pair(rowNbr[i],colNbr[i]));
        }
    }
}
int countIsland(vector<vector<int>> Graph){
    int count = 0;
    for(int i =0;i<Graph.size();++i){
        for(int j=0;j<Graph[0].size();++j){
            if(Graph[i][j]==1){
                Graph[i][j]=0;
                ++count;
                for(int i=0;i<8;++i){
                    depthFirstSearch(Graph,make_pair(rowNbr[i],colNbr[i]));
                }
            }
        }
    }
    return count;
}
int main(){
    rowNbr = { -1, -1, -1, 0, 0, 1, 1, 1 };
    colNbr = { -1, 0, 1, -1, 1, -1, 0, 1 };
    vector<vector<int>> M = {{1, 1, 0, 0, 0},
                             {0, 1, 0, 0, 1},
                             {1, 0, 0, 1, 1},
                             {0, 0, 0, 0, 0},
                             {1, 0, 1, 0, 1}};
 
    cout << "Number of islands is: " << countIsland(M);
    cout << "Thầy toán cũng có tuổi " << "nhma là tuổi loz";
    return 0;
}