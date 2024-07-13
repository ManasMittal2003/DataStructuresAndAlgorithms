int modulo=1e9+7;
int solve(int ind,int curr,int &k,int &n,vector<int> &arr,vector<vector<int>> &dp){

	if(ind>=n){
		if(curr==k){
			return 1;
		}
		return 0;
	}
	if(curr>k){
		return 0;
	}
	if(dp[ind][curr]!=-1){
		return dp[ind][curr];
	}
    int take=solve(ind + 1, curr + arr[ind], k, n, arr,dp);
    int nt=solve(ind+1,curr,k,n,arr,dp);
	return dp[ind][curr]=(take+nt)%modulo;
}
int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	vector<vector<int>> dp(n,vector<int> (k+1,-1));
	return solve(0,0,k,n,arr,dp);

}
