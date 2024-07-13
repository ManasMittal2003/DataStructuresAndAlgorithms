/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root, int& maxsum){
        if(root==NULL) return 0;

        int lh= max(dfs(root->left,maxsum),0);
        int rh= max(dfs(root->right,maxsum),0);
        maxsum= max(maxsum,lh+rh+root->val);
        return max(lh,rh)+root->val;
    }

    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        dfs(root,maxsum);
        return maxsum;
    }
};
