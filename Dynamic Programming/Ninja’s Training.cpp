#include<bits/stdc++.h>
int solve(int row,int col,int &n,vector<vector<int>> &points,vector<vector<int>> &dp){
    if(row==n-1){
        return points[row][col];
    }
    if(dp[row][col]!=-1){
        return dp[row][col];
    }
    int maxans=INT_MIN;
    for(int i=0;i<3;i++){
        if(i!=col){
            int res=points[row][col]+solve(row+1,i,n,points,dp);
            maxans=max(maxans,res);
        }
    }
    return dp[row][col]=maxans;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int> (3,-1));
    int ans=INT_MIN;
    for(int i=0;i<3;i++){
        int res=solve(0,i,n,points,dp);
        ans=max(ans,res);
    }
    return ans;
}
