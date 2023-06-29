#include <algorithm>
int minCharsforPalindrome(string str) {
	// Write your code here.
	string rev = str;
	reverse(rev.begin(), rev.end());
	str += "#" + rev;
	int n = str.size(), i = 0, j = 1;
	vector<int> lps(n);
	while(j < n)
	{
		if(str[i] == str[j])
		{
			lps[j] = i + 1;
			i++, j++;
		}
		else{
			if(i == 0)
				j++;
			else
				i = lps[i - 1];
		}
	}
	return rev.size() - lps.back();
}