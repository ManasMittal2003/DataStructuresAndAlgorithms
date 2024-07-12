bool solve(int ind,int curr,int total,int &n,vector<int> &arr,vector<vector<int>> &dp){
	if(curr==total){
		return true;
	}
	if(ind>=n){
		return false;
	}
	if(curr>total){
		return false;
	}
	if(dp[ind][curr]!=-1){
		return dp[ind][curr];
	}
	bool take=solve(ind+1,curr+arr[ind],total-arr[ind],n,arr,dp);
	bool ntake=solve(ind+1,curr,total,n,arr,dp);
	return dp[ind][curr]=(take||ntake);
}
bool canPartition(vector<int> &arr, int n)
{
	int total=0;
	for(int i=0;i<n;i++){
		total+=arr[i];
	}
	vector<vector<int>> dp(n,vector<int> (total+1,-1));
	return solve(0,0,total,n,arr,dp);
}
