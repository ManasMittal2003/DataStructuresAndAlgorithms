class Solution {
  public:
    int solve(int strt,vector<int> &height,vector<int> &dp){
        if(strt==0){
            return 0;
        }
        if(dp[strt]!=-1){
            return dp[strt];
        }
        int one=INT_MAX;
        int two=INT_MAX;
        one=solve(strt-1,height,dp)+abs(height[strt]-height[strt-1]);
        if(strt>1){
            two=solve(strt-2,height,dp)+abs(height[strt]-height[strt-2]);
        }
        return dp[strt]=min(one,two);
    }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n,-1);
        return solve(n-1,height,dp);
    }
};
