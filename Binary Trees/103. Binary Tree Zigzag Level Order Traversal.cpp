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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool left = false;
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp(size, -1);
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (left) {
                    temp[size - i - 1] = node->val;
                } else {
                    temp[i] = node->val;
                }
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            ans.push_back(temp);
            left = !left;
        }
        return ans;
    }
};
