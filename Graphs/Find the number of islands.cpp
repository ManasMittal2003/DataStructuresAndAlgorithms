class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int row,int col,vector<vector<bool>> &vis,vector<vector<char>>& grid){
        vis[row][col]=true;
        int n=grid.size();
        int m=grid[0].size();
        int drow[]={0,-1,-1,-1,0,1,1,1};
        int dcol[]={-1,-1,0,1,1,1,0,-1};
        for(int i=0;i<8;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&grid[nrow][ncol]=='1'&&vis[nrow][ncol]==false){
                dfs(nrow,ncol,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'&&vis[i][j]==false){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};
