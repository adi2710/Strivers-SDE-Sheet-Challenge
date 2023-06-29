vector<int> stringMatch(string text, string pattern) {
	// Write your code here.
	int mod = 1e9 + 7, hash_text = 0, hash_patt = 0, place_val = 1, n = text.size(), m = pattern.size();
	for(int i = 0; i + 1 < m; i++)
		place_val = (place_val * 26ll) % mod;
	vector<int> ans;
	for(int i = 0; i < n; i++)
	{
		hash_text = (hash_text * 26ll + text[i] - 'a') % mod;
		if(i < m)
			hash_patt = (hash_patt * 26ll + pattern[i] - 'a') % mod;
		if(i + 1 >= m)
		{
			if(hash_text == hash_patt)
			{
				bool match = true;
				for(int j = i - m + 1; j <= i; j++)
				{
					if(text[j] != pattern[j - i + m - 1])
					{
						match = false;
						break;
					}
				}
				if(match)
					ans.push_back(i - m + 2);
			}
			int last = (1ll * (text[i - m + 1] - 'a') * place_val) % mod;
			hash_text = (hash_text - last + mod) % mod;
		}
	}
	return ans;
}
