class Solution {
public:
    int solve(int ind, vector<int>& nums, vector<int>& dp) {
        if (ind < 0) {
            return 0;
        }
        if (dp[ind] != -1) {
            return dp[ind];
        }
        int take = solve(ind - 2, nums, dp) + nums[ind];
        int nt = solve(ind - 1, nums, dp);
        return dp[ind] = max(take, nt);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(nums.size(), -1);
        return solve(n-1, nums, dp);
    }
};
