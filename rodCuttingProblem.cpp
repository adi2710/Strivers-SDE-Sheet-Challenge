int solve(int len, vector<int> &price, vector<int> &dp)
{
	if(len == 0)
		return 0;
	if(dp[len] != -1)
		return dp[len];
	int ans = 0;
	for(int i = 0; i < len; i++)
		ans = max(ans, price[i] + solve(len - i - 1, price, dp));
	return dp[len] = ans;
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	vector<int> dp(n + 1, -1);
	return solve(n, price, dp);
}