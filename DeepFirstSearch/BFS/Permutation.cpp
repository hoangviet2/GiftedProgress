//
//  Permutation.cpp
//  BFS
//
//  Created by Hoang Viet on 04/11/2021.
//

#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
int Permutation(){
    int n;
    cin>>n;

    string rawString = "", increasing="";

    for(int i=0;i<n;i++){

        int x;cin>>x;

        rawString += char(x + '0');

    }
    
    //cout<<rawString;

    increasing = rawString;

    sort(increasing.begin(), increasing.end());

    queue<string> queue;

    queue.push(rawString);

    map<string, int> visit;

    visit[rawString] = 1;

 

    while(!queue.empty()){

        string temp = queue.front();

        queue.pop();

        if(temp == increasing){

            break;

        }

        for(int i = 2;i<=temp.size();i++){

            string z = temp;

            reverse(z.begin(), z.begin()+i);

            if(visit[z]==0){

                visit[z] = visit[temp]+1;

                queue.push(z);

            }

        }

    }
    return visit[increasing]-1;
}
//int main(){
//    cout<<Permutation();
//    return 0;
//}
