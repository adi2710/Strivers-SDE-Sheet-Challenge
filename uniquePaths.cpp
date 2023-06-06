#include <bits/stdc++.h> 
int uniquePaths(int n, int m) {
	// Write your code here.
	vector<vector<int>> dp(n, vector<int> (m));
	for(int c = 0; c < m; c++)
		dp[0][c] = 1;
	for(int r = 0; r < n; r++)
		dp[r][0] = 1;
	for(int r = 1; r < n; r++)
	{
		for(int c = 1; c < m; c++)
			dp[r][c] = dp[r - 1][c] + dp[r][c - 1];
	}
	return dp[n - 1][m - 1];
}