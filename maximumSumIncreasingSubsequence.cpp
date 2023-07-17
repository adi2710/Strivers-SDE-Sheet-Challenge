#include <bits/stdc++.h> 
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// Write your code here
	int sz = *max_element(rack.begin(), rack.end());
	vector<int> dp(sz + 1);
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		ans = max(ans, dp[rack[i]] + rack[i]);
		for(int j = i + 1; j < n; j++)
		{
			if(rack[i] < rack[j])
				dp[rack[j]] = max(dp[rack[j]], rack[i] + dp[rack[i]]);
		}
	}
	return ans;
}