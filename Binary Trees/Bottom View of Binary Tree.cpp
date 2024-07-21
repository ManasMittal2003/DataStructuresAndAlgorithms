class Solution {
  public:
    vector <int> bottomView(Node *root) {
        map<int,int> mapping;
        queue<pair<int,Node *>> q;
        q.push(make_pair(0,root));
        vector<int> ans;
        while(!q.empty()){
            pair<int,Node *> p=q.front();
            q.pop();
            int hd=p.first;
            Node *temp=p.second;
            mapping[hd]=temp->data;
            if(temp->left) q.push(make_pair(hd-1,temp->left));
            if(temp->right) q.push(make_pair(hd+1,temp->right));
        }
        for(auto i:mapping){
            ans.push_back(i.second);
        }
        return ans;
    }
};
