#include <bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	vector<int> ans;
	priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int i = 0; i < n; i++)
    {
        if(!minHeap.empty() && minHeap.top() < arr[i])
            minHeap.push(arr[i]);
        else
            maxHeap.push(arr[i]);
        if((int)maxHeap.size() - (int)minHeap.size() >= 2)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if((int)minHeap.size() - (int)maxHeap.size() >= 2)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if(i & 1)
            ans.push_back((maxHeap.top() + minHeap.top()) / 2);
        else
            ans.push_back(maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top());
    }
	return ans;
}