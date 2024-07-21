/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    void traverse_left(Node *root,vector<int> &ans){
        if(root==NULL||(root->left==NULL&&root->right==NULL)){
            return;
        }
        ans.push_back(root->data);
        if(root->left){
            traverse_left(root->left,ans);
        }
        else{
            traverse_left(root->right,ans);
        }
    }
    void traverse_leaf(Node *root,vector<int> &ans){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        traverse_leaf(root->left,ans);
        traverse_leaf(root->right,ans);
        
    }
    void traverse_right(Node *root,vector<int> &ans){
        if(root==NULL||(root->left==NULL&&root->right==NULL)){
            return;
        }
        if(root->right){
            traverse_right(root->right,ans);
        }
        else{
            traverse_right(root->left,ans);
        }
        ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        ans.push_back(root->data);
        traverse_left(root->left,ans);
        traverse_leaf(root->left,ans);
        traverse_leaf(root->right,ans);
        traverse_right(root->right,ans);
        return ans;
        
    }
};
