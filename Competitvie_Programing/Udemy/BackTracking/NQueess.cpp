#include <bits/stdc++.h>
#define int long long int
#define F first
#define S second
#define pb push_back
using namespace std;

bool canplace(int board[][20],int n, int x,int y){
	// column
	for(int k=0;k<x;++k){
		if(board[k][y] == 1){
			return false;
		}
	}
	// left dia
	int i = x;
	int j = y;
	while(i>=0 && j>=0){
		if(board[i][j] == 1){
			return false;
		}
		i--; j--;
	}

	// right dia
	i = x;
	j = y;
	while(i>=0 && j>=0){
		if(board[i][j] == 1){
			return false;
		}
		i--; j++;
	}
	return true;
}

void printBoard(int n,int board[][20]){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}

bool sloveNquees(int n,int board[][20], int i){
	//base case
	if(i==n){
		// print the board
		printBoard(n,board);
		return true;
	}

	//rec case
	// try to place a queen in a row
	for(int j=0;j<n;j++){
		if(canplace(board,n,i,j)){
			board[i][j] = 1;
			bool success = sloveNquees(n,board,i+1);
			if(success){
				return true;
			}
			// backtrack
			board[i][j] = 0;
		}

	}
	return false;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int board [20][20] = {0};
	int n;
	cin>>n;
	sloveNquees(n,board,0);
	return 0;
}