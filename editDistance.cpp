#include <algorithm>
int editDistance(string s, string t)
{
    //write you code here
    int n = s.size(), m = t.size();
	vector<int> dp(m + 1), new_dp(m + 1);
    iota(dp.begin(), dp.end(), 0);
	for(int i = 1; i <= n; i++)
	{
        new_dp[0] = i;
		for(int j = 1; j <= m; j++)
		{
			if(s[i - 1] == t[j - 1])
				new_dp[j] = dp[j - 1];
			else
				new_dp[j] = 1 + min({new_dp[j - 1], dp[j], dp[j - 1]});
		}
		dp = new_dp;
	}
	return dp[m];
}