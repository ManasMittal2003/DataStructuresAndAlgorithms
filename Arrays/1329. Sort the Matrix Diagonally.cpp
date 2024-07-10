class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            int row = 0, col = i;
            while (row < n && col < m) {
                temp.push_back(mat[row][col]);
                ++row;
                ++col;
            }
            sort(temp.begin(), temp.end());
            row = 0, col = i;
            for (int val : temp) {
                mat[row][col] = val;
                ++row;
                ++col;
            }
        }
        for (int i = 1; i < n; ++i) {
            vector<int> temp;
            int row = i, col = 0;
            while (row < n && col < m) {
                temp.push_back(mat[row][col]);
                ++row;
                ++col;
            }
            sort(temp.begin(), temp.end());
            row = i, col = 0;
            for (int val : temp) {
                mat[row][col] = val;
                ++row;
                ++col;
            }
        }

        return mat;
    }
};
