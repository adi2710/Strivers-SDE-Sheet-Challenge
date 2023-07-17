#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	// Write your code here
	int min_prod = 1, max_prod = 1, ans = INT_MIN;
	for(int x : arr)
	{
		int tmp = min({min_prod * x, max_prod * x, x});
		max_prod = max({min_prod * x, max_prod * x, x});
		min_prod = tmp;
		ans = max(ans, max_prod);
	}
	return ans;
}
