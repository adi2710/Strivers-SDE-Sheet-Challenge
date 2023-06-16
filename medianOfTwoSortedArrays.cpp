double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
	if(a.size() > b.size())
		return median(b, a);
	int l = 0, r = a.size();
	int n1 = a.size(), n2 = b.size();
	while(l <= r)
	{
		int cut1 = l + (r - l) / 2;
		int cut2 = (n1 + n2 + 1) / 2 - cut1;
		int l1 = cut1 == 0 ? INT_MIN : a[cut1 - 1], r1 = cut1 == n1 ? INT_MAX : a[cut1];
		int l2 = cut2 == 0 ? INT_MIN : b[cut2 - 1], r2 = cut2 == n2 ? INT_MAX : b[cut2];
		if(l1 <= r2 && l2 <= r1)
		{
			if((n1 + n2) & 1)
				return max(l1, l2);
			else
				return (max(l1, l2) + min(r1, r2)) / 2.0;
		}
		else if(l1 > r2)
			r = cut1 - 1;
		else
			l = cut1 + 1;
	}
	return 0;
}