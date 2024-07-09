#include <bits/stdc++.h> 
int solve(int row,int col,int m,int n,vector<vector<int>> &dp){
	if(row==m-1&&col==n-1){
		return 1;
	}
	if(dp[row][col]!=-1){
		return dp[row][col];
	}
	int right=0;
	int down=0;
	if(col+1<n){
		right=right+solve(row,col+1,m,n,dp);
	}
	if(row+1<m){
		down=down+solve(row+1,col,m,n,dp);
	}
	return dp[row][col]=right+down;
}
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m,vector<int> (n,-1));
	return solve(0,0,m,n,dp);
}
