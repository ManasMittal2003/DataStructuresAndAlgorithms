class Solution {
public:
    bool solve(int ind, int curr, int& total, int& n, vector<int>& nums,
               vector<vector<int>>& dp) {
        if ((curr == total / 2) && (curr * 2 == total)) {
            return true;
        }
        if (curr > total / 2) {
            return false;
        }
        if (ind >= n) {
            return false;
        }
        if (dp[ind][curr] != -1) {
            return dp[ind][curr];
        }
        int take = solve(ind + 1, curr + nums[ind], total, n, nums, dp);
        int ntake = solve(ind + 1, curr, total, n, nums, dp);
        return dp[ind][curr] = take || ntake;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            total += nums[i];
        }
        vector<vector<int>> dp(n, vector<int>(total + 1, -1));
        return solve(0, 0, total, n, nums, dp);
    }
};
