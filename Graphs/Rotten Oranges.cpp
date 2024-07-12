class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        int dr[4]={0,-1,0,1};
        int dc[4]={-1,0,1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    vis[i][j]=true;
                }
            }
        }
        while(!q.empty()){
            int temp=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            ans=max(temp,ans);
            q.pop();
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]==1&&vis[nr][nc]==false){
                    q.push({temp+1,{nr,nc}});
                    vis[nr][nc]=true;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&vis[i][j]==false){
                    return -1;
                }
            } 
        }
        return ans;
    }
};
