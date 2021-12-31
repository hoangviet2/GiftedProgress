//
//  main.cpp
//  Xcode
//
//  Created by Viet Hoang on 12/12/2021.
//

//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > a(20,vector<int> (20,0));
//int a[20][20]={0};
vector<vector<int> > v(20,vector<int> (20,0));
//int v[20][20]={0};

int f=0;

void dfs(int x,int y,int n){

    if(x==n-1&&y==n-1){

        f++;

        v[x][y]=0;

        return;

    }

    v[x][y]=1;

    if(x+1<n&&a[x+1][y]==0&&v[x+1][y]==0)

        dfs(x+1,y,n);

    if(x-1>=0&&a[x-1][y]==0&&v[x-1][y]==0)

        dfs(x-1,y,n);

    if(y-1>=0&&a[x][y-1]==0&&v[x][y-1]==0)

        dfs(x,y-1,n);

    if(y+1<n&&a[x][y+1]==0&&v[x][y+1]==0)

        dfs(x,y+1,n);

 

    v[x][y]=0;

    if(x==0&&y==0)

        cout<<f<<"\n";

}

int main(){

    int t;

    cin>>t;

 

    while(t--){

        int n;

        cin>>n;

 

        int i,j;

        for(i=0;i<n;i++){

            for(j=0;j<n;j++){

                cin>>a[i][j];

            }

        }

        if(a[n-1][n-1]==1){
            cout<<"0"<<"\n";
        }
        else{

            f=0;

            dfs(0,0,n);

        }

    }

}
