int knapsack(int i, int curWt, vector<int> &val, vector<int> &wt, int &maxWt, vector<vector<int>> &dp)
{
	if(i == wt.size())
		return 0;
	if(dp[i][curWt] != -1)
		return dp[i][curWt];
	int skip = knapsack(i + 1, curWt, val, wt, maxWt, dp), take = 0;
	if(curWt + wt[i] <= maxWt)
		take = val[i] + knapsack(i + 1, curWt + wt[i], val, wt, maxWt, dp);
	return dp[i][curWt] = max(take, skip);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	vector<vector<int>> dp(n, vector<int> (w + 1, -1));
	return knapsack(0, 0, values, weights, w, dp);
}