int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int l = 0, r = arr.size() - 1, n = arr.size();
	while(l <= r)
	{
		int mid = l + (r - l) / 2;
		int first = -1, second = -1;
		if(mid < n && arr[mid] == arr[mid + 1])
			first = mid, second = mid + 1;
		else if(mid - 1 >= 0 && arr[mid] == arr[mid - 1])
			first = mid - 1, second = mid;
		else
			return arr[mid];
		if(second & 1 ^ 1)
			r = first - 1;
		else
			l = second + 1;
	}
	return -1;
}