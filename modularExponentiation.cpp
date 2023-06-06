#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	int res = 1;
	while(n)
	{
		if(n & 1)
			res = (1ll * res * x) % m;
		x = (1ll * x * x) % m;
		n >>= 1;
	}
	return res;
}