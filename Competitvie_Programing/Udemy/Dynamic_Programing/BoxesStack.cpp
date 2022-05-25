#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compareBoxes(vector<int> b1,vector<int> b2){
    return b1[2] > b2[2];
}
bool isFit(vector<int> box1,vector<int> box2){
    return box1[0]>box2[0] && box1[1]>box2[1] && box1[2]>box2[2];
}
int boxStacking(vector<vector<int>> boxes){
    // 1.sorting
    sort(boxes.begin(),boxes.end(),compareBoxes);

    // dp
    vector<int> dp(boxes.size()+1,0);
    for(int i=0;i<boxes.size();++i){
        dp[i] = boxes[i][2]; // add height
    }
    
    for(int i=1;i<boxes.size();++i){
        for(int j=0;j<i;++j){
            if(isFit(boxes[i],boxes[j])){
                int currheight = boxes[i][2];

                if(dp[j] + currheight > dp[i]){
                    dp[i] = dp[j] + currheight;
                }
            }
        }
    }

    int maxHeight = 0;
    for(int i=0;i<boxes.size();++i){
        cout<<dp[i]<<" ";
        maxHeight = max(dp[i],maxHeight);
    }
    return maxHeight;
}
int main() {
    vector<vector<int> > boxes = {
        {2,1,2},
        {3,2,3},
        {2,2,8},
        {2,3,4},
        {2,2,1},
        {4,4,5},
    };
    cout<<"Max Height: "<<boxStacking(boxes);
	// your code goes here
	return 0;
}

