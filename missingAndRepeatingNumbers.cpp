#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int xor_sum = 0;
	for(int i = 0; i < n; i++)
		xor_sum ^= (i + 1) ^ arr[i];
	int lsb = 0;
	for(int i = 0; i < 31; i++)
	{
		if(xor_sum & (1 << i))
		{
			lsb = 1 << i;
			break;
		}
	}
	pair<int, int> ans = {0, 0};
	for(int i = 0; i < n; i++)
	{
		if(arr[i] & lsb)
			ans.first ^= arr[i];
		else
			ans.second ^= arr[i];
		if((i + 1) & lsb)
			ans.first ^= (i + 1);
		else
			ans.second ^= (i + 1);
	}
	for(int i = 0; i < n; i++)
	{
		if(arr[i] == ans.first)
		{
			swap(ans.first, ans.second);
			break;
		}
	}
	return ans;
}
