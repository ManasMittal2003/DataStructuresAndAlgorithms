class Solution {
public:
    int solve(int step, int n, vector<int>& dp) {
        if (step > n) {
            return 0;
        }
        if (step == n) {
            return 1;
        }
        if (dp[step] != -1) {
            return dp[step];
        }
        int one = solve(step + 1, n, dp);
        int two = solve(step + 2, n, dp);
        return dp[step] = one + two;
    }
    int climbStairs(int n) {
        vector<int> dp(n, -1);
        return solve(0, n, dp);
    }
};
