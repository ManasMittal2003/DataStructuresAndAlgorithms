class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool check(int strt,vector<int> &parent,vector<bool> &vis,vector<int> adj[]){
        vis[strt]=true;
        queue<int> q;
        q.push(strt);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto i:adj[node]){
                if(vis[i]==true&&parent[node]!=i){
                    return true;
                }
                if(vis[i]==false){
                    parent[i]=node;
                    vis[i]=true;
                    q.push(i);
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
