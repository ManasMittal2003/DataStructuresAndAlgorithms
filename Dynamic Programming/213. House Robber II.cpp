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
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> arr1;
        vector<int> arr2;
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                arr1.push_back(nums[i]);
            }
            if (i != n - 1) {
                arr2.push_back(nums[i]);
            }
        }

        int n1 = arr1.size();
        vector<int> dp1(n1, -1);
        int ans1 = solve(n1 - 1, arr1, dp1);

        int n2 = arr2.size();
        vector<int> dp2(n2, -1);
        int ans2 = solve(n2 - 1, arr2, dp2);

        return max(ans1, ans2);
    }
};
