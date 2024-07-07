class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int strt,vector<int> &ans,vector<bool> &vis,vector<int> adj[]){
        vis[strt]=true;
        ans.push_back(strt);
        for(auto neigh:adj[strt]){
            if(vis[neigh]==false){
                dfs(neigh,ans,vis,adj);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> vis(V+1,false);
        dfs(0,ans,vis,adj);
        return ans;
    }
};
