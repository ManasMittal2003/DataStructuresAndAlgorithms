#include<bits/stdc++.h>
int modulo=1e9+7;
int solve(int row,int col,int n,int m,vector<vector<int>> &mat,vector<vector<int>> &dp){
    if(row==n-1&&col==m-1){
        return 1;
    }
    if(dp[row][col]!=-1){
        return dp[row][col];
    }
    int right=0;
	int down=0;
	if(col+1<m&&mat[row][col+1]!=-1){
		right=solve(row,col+1,n,m,mat,dp);
	}
	if(row+1<n&&mat[row+1][col]!=-1){
		down=solve(row+1,col,n,m,mat,dp);
	}
	return dp[row][col]=(right+down)%modulo;
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    if(mat[0][0]==-1||mat[n-1][m-1]==-1){
        return 0;
    }
    vector<vector<int>> dp(n,vector<int> (m,-1));
    return solve(0,0,n,m,mat,dp);
}
