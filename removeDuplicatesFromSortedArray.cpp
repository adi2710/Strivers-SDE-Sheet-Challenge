int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int l = 0;
	for(int r = 1; r < n; r++)
	{
		if(arr[l] != arr[r])
			arr[++l] = arr[r];
	}
	return l + 1;
}