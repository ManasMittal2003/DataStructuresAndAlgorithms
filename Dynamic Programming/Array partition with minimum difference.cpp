void solve(int ind,int curr,int total,int &minans,int &n,vector<int> &arr,vector<vector<int>> &dp){
	if(ind>=n){
		return;
	}
	if(dp[ind][curr]!=-1){
		minans=min(minans,dp[ind][curr]);
		return;
	}
	dp[ind][curr]=minans=min(minans,abs(curr-total));
	solve(ind+1,curr+arr[ind],total-arr[ind],minans,n,arr,dp);
	solve(ind+1,curr,total,minans,n,arr,dp);
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
	
	int minans=INT_MAX;
	int total=0;
	for(auto i:arr){
		total+=i;
	}
	vector<vector<int>> dp(n,vector<int> (total+1,-1));
	solve(0,0,total,minans,n,arr,dp);
	return minans;
}
