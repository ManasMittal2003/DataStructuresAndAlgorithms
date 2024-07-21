class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        map<int,int> mapping;
        queue<pair<int,Node *>> q;
        q.push(make_pair(0,root));
        vector<int> ans;
        while(!q.empty()){
            pair<int,Node *> p=q.front();
            q.pop();
            int hd=p.first;
            Node *temp=p.second;
            if(mapping.find(hd)==mapping.end()){
                mapping[hd]=temp->data;
            }
            if(temp->left) q.push(make_pair(hd-1,temp->left));
            if(temp->right) q.push(make_pair(hd+1,temp->right));
        }
        for(auto i:mapping){
            ans.push_back(i.second);
        }
        return ans;
    }

};
