class Solution {
  public:
    int solve(int strt,int &k,vector<int> &height,vector<int> &dp){
        if(strt==0){
            return 0;
        }
        if(dp[strt]!=-1){
            return dp[strt];
        }
        int minres=INT_MAX;
        for(int i=1;i<=k;i++){
            if(strt-i>=0){
                int result=solve(strt-i,k,height,dp)+abs(height[strt]-height[strt-i]);
                minres=min(minres,result);
            }
        }
        return dp[strt]=minres;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> dp(n+1,-1);
        return solve(n-1,k,height,dp);
    }
};
