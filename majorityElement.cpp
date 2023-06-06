#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int num = arr[0], cnt = 1;
	for(int i = 1; i < n; i++)
	{
		if(num == arr[i])
			cnt++;
		else
			cnt--;
		if(cnt == 0)
		{
			num = arr[i];
			cnt = 1;
		}
	}
	cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(num == arr[i])
			cnt++;
	}
	if(cnt > n / 2)
		return num;
	return -1;
}