#include <vector>
int lcs(string s, string t)
{
	//Write your code here
	int n = s.size(), m = t.size();
	vector<int> dp(m + 1), new_dp(m + 1);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(s[i - 1] == t[j - 1])
				new_dp[j] = 1 + dp[j - 1];
			else
				new_dp[j] = max(new_dp[j - 1], dp[j]);
		}
		dp = new_dp;
	}
	return dp[m];
}