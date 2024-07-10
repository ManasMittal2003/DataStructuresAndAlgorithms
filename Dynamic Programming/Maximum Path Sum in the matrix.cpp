#include <bits/stdc++.h> 
int solve(int row,int col,int &n,int &m,vector<vector<int>> &matrix,vector<vector<int>> &dp){
    if(row==n-1){
        return matrix[row][col];
    }
    if(dp[row][col]!=-1){
        return dp[row][col];
    }
    int first=INT_MIN;
    int second=INT_MIN;
    int third=INT_MIN;
    if(col-1>=0){
        first=matrix[row][col]+solve(row+1,col-1,n,m,matrix,dp);
    }
    second=matrix[row][col]+solve(row+1,col,n,m,matrix,dp);
    if(col+1<m){
        third=matrix[row][col]+solve(row+1,col+1,n,m,matrix,dp);
    }
    return dp[row][col]=max(max(first,second),third);
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int ans=INT_MIN;
    vector<vector<int>> dp(n,vector<int> (m,-1));
    for(int i=0;i<m;i++){
        ans=max(ans,solve(0,i,n,m,matrix,dp));
    }
    return ans;
}
