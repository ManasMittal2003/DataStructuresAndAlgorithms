class Solution {
  public:
    void dfs(unordered_map<int,vector<int>> &graph,int strt,vector<bool> &vis){
        vis[strt]=true;
        for(auto i:graph[strt]){
            if(vis[i]==false){
                dfs(graph,i,vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool> vis(V+1,false);
        unordered_map<int,vector<int>> graph;
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++){
                if(adj[i][j]==1){
                    graph[i+1].push_back(j+1);
                    graph[j+1].push_back(i+1);
                }
            }
        }
        int cnt=0;
        for(int i=1;i<=V;i++){
            if(vis[i]==false){
                cnt++;
                dfs(graph,i,vis);
            }
        }
        return cnt;
    }
};
