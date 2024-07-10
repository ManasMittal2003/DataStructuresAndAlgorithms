class Solution {
public:
    void solve(vector<vector<int>>& image,int sr,int sc,int &newColor,vector<vector<bool>> &vis,int &prevcol){
        vis[sr][sc]=true;
        int n=image.size();
        int m=image[0].size();
        int drow[]={0,-1,0,1};
        int dcol[]={-1,0,1,0};
        for(int i=0;i<4;i++){
            int nrow=sr+drow[i];
            int ncol=sc+dcol[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&image[nrow][ncol]==prevcol&&vis[nrow][ncol]==false){
                solve(image,nrow,ncol,newColor,vis,prevcol);
            }
        }
        image[sr][sc]=newColor;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m=image[0].size();
        int prevcol=image[sr][sc];
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        solve(image,sr,sc,newColor,vis,prevcol);
        return image;
    }
};
