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
    void solve(TreeNode *root,int cord,int lvl,map<int,map<int,multiset<int>>> &ds){
        if(root==NULL){
            return;
        }
        ds[cord][lvl].insert(root->val);
        solve(root->left,cord-1,lvl+1,ds);
        solve(root->right,cord+1,lvl+1,ds);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> ds;
        solve(root,0,0,ds);
        for(auto i:ds){
            vector<int> temp;
            for(auto j:i.second){
                for(auto k:j.second){
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
