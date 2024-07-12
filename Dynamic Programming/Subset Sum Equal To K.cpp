#include <bits/stdc++.h> 
bool solve(int ind,int target,vector<int> &arr,vector<vector<int>> &dp){
    if(target==0){
        return dp[ind][target]=true;
    }
    if(ind==0){
        return target==arr[ind];
    }
    if(dp[ind][target]!=-1){
        return dp[ind][target];
    }
    bool take=false,ntake=false;
    if (target >= arr[ind]) {
        take = solve(ind - 1,target - arr[ind], arr, dp);
    }
    ntake=solve(ind-1,target,arr,dp);
    return dp[ind][target]=(ntake|take);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n,vector<int> (k+1,-1));
    return solve(n-1,k,arr,dp);
}
