#include <bits/stdc++.h> 
int drow[2]={0,1};
int dcol[2]={1,0};
int solve(int row,int col,int &n,int &m,vector<vector<int>> &grid,vector<vector<int>> &dp){
    if(row==n-1&&col==m-1){
        return grid[row][col];
    }
    if(dp[row][col]!=-1){
        return dp[row][col];
    }
    int minres=INT_MAX;
    for(int i=0;i<2;i++){
        int nr=row+drow[i];
        int nc=col+dcol[i];
        if(nr<n&&nc<m){
            int res=grid[row][col]+solve(nr,nc,n,m,grid,dp);
            minres=min(minres,res);
        }
    }
    return dp[row][col]=minres;
}
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(n,vector<int> (m,-1));
    return solve(0,0,n,m,grid,dp);
}
