#include <bits/stdc++.h> 
int solve(int row,int col,int &n,vector<vector<int>> &triangle,vector<vector<int>> &dp){
	if(row==n-1){
		return triangle[row][col];
	}
	if(dp[row][col]!=-1){
		return dp[row][col];
	}
	int one=triangle[row][col]+solve(row+1,col,n,triangle,dp);
	int two=triangle[row][col]+solve(row+1,col+1,n,triangle,dp);
	return dp[row][col]=min(one,two);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp;
	for(int i=0;i<n;i++){
		vector<int> temp(i+1,-1);
		dp.push_back(temp);
	}
	return solve(0,0,n,triangle,dp);
}
