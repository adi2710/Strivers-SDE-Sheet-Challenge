#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	// Write your code here.
	string ans = "1";
	for(int i = 1; i < n; i++)
	{
		string next;
		for(int j = 0, k = 0; j < ans.size();)
		{
			while(k < ans.size() && ans[j] == ans[k]) k++;
			next += to_string(k - j);
			next += ans[j];
			j = k;
		}
		ans = next;
	}
	return ans;
}