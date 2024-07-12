class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool check(int strt,vector<int> &parent,vector<bool> &vis,vector<int> adj[]){
        vis[strt]=true;
        for(auto i:adj[strt]){
            if(vis[i]==true&&parent[strt]!=i){
                return true;
            }
            else if(vis[i]==false){
                parent[i]=strt;
                bool ans=check(i,parent,vis,adj);
                if(ans){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V+1,false);
        vector<int> parent(V+1,-1);
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                bool ans=check(i,parent,vis,adj);
                if(ans==true){
                    return true;
                }
            }
        }
        return false;
    }
};
