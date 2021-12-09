#include <iostream>
#include <vector>
#include <map>
using namespace std;
static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
bool isSafe(vector<vector<int>> Graph,int i,int j){
    return (i >= 0) && (j >= 0) && (i <= (Graph.size() - 1)) && (j <= (Graph[0].size() - 1));
}
void DFS(vector<vector<int>> &Graph, int i, int j){
    if (isSafe(Graph, i, j)){
        if(Graph[i][j] == 1){
            Graph[i][j] = 0;
            for(int ind=0;ind<8;++ind){
                DFS(Graph,i+rowNbr[ind],j+colNbr[ind]);
            }
        }
    }
}

int countIslands(vector<vector<int>> &Graph){
    int count = 0;
    for (int i = 0; i < Graph.size(); i++){
        for (int j = 0; j < Graph[0].size(); j++){
            if (Graph[i][j] == 1){
                Graph[i][j] = 0;
                count++;
                for(int ind=0;ind<8;++ind){
                    DFS(Graph,i+rowNbr[ind],j+colNbr[ind]);
                }
            }
        }
    }
    return count;
}
int main(){
    vector<vector<int>> M = {{1, 1, 0, 0, 0},
                            {0, 1, 0, 0, 1},
                            {1, 0, 0, 1, 1},
                            {0, 0, 0, 0, 0},
                            {1, 0, 1, 0, 1}};

    cout << "Number of islands is: " << countIslands(M);
    return 0;
}
