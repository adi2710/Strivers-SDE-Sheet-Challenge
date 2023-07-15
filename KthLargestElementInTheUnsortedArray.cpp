#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int x : arr)
	{
		pq.push(x);
		if(pq.size() > K)
			pq.pop();
	}
	return pq.top();
}