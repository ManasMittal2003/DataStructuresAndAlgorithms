/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    pair<bool, int> solve(TreeNode* root) {
        if (root == NULL) {
            return {true, 0};
        }
        pair<bool, int> left = solve(root->left);
        pair<bool, int> right = solve(root->right);
        if (left.first == false || right.first == false) {
            return {false, 0};
        }
        int h1 = left.second;
        int h2 = right.second;
        if (abs(h1 - h2) > 1) {
            return {false, 0};
        }
        return {true, max(h1, h2) + 1};
    }
    bool isBalanced(TreeNode* root) {
        pair<bool, int> ans = solve(root);
        return ans.first;
    }
};
