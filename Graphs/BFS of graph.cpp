class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> graph[]) {
        vector<bool> vis(V+1,false);
        queue<int> q;
        vector<int> ans;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto neighbour:graph[node]){
                if(vis[neighbour]==false){
                    q.push(neighbour);
                    vis[neighbour]=true;
                }
            }
        }
        return ans;
    }
};
