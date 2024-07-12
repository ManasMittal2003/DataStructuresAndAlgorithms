class Solution {
public:
    int solve(int row, int c1, int c2, int& n, int& m,
              vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        if (row == n - 1) {
            if (c1 == c2) {
                return grid[row][c1];
            } else {
                return grid[row][c1] + grid[row][c2];
            }
        }
        if (dp[row][c1][c2] != -1) {
            return dp[row][c1][c2];
        }
        int cherry = grid[row][c1];
        if (c1 != c2) {
            cherry += grid[row][c2];
        }
        int ans = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nrow = row + 1;
                int nc1 = c1 + i;
                int nc2 = c2 + j;
                if (nc1 >= 0 && nc1 < m && nc2 >= 0 && nc2 < m) {
                    ans = max(ans, solve(nrow, nc1, nc2, n, m, grid, dp));
                }
            }
        }
        return dp[row][c1][c2] = ans + cherry;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, -1)));
        return solve(0, 0, m - 1, n, m, grid, dp);
    }
};
