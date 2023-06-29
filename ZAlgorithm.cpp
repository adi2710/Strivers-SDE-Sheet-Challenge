int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here
	vector<int> lps(m);
	int i = 0, j = 1, ans = 0;
	while(j < m)
	{
		if(p[i] == p[j])
		{
			lps[j] = i + 1;
			i++, j++;
		}
		else
		{
			if(i == 0)
				j++;
			else
				i = lps[i - 1];
		}
	}
	i = 0, j = 0;
	while(j < n)
	{
		if(p[i] == s[j])
		{
			i++, j++;
			if(i == m){
				i = lps[i - 1];
				ans++;
			}
		}
		else
		{
			if(i == 0)
				j++;
			else
				i = lps[i - 1];
		}
	}
	return ans;
}