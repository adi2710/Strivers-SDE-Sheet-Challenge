#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;
	for(int i = 0; i + 2 < n; i++)
	{
		int j = i + 1, k = n - 1;
		while(j < k)
		{
			int sum = arr[i] + arr[j] + arr[k];
			if(sum == K)
			{
				ans.push_back({arr[i], arr[j], arr[k]});
				j++, k--;
				while(j < k && arr[j - 1] == arr[j]) j++;
				while(j < k && arr[k + 1] == arr[k]) k--;
			}
			else if(sum > K)
				k--;
			else
				j++;
		}
		while(i + 1 < n && arr[i] == arr[i + 1]) i++;
	}
	return ans;
}