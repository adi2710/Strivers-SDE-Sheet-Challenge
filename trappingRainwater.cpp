#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    long ans = 0;
    vector<long> suf(n);
    for(long i = n - 1, mx = INT_MIN; i >= 0; i--)
    {
        mx = max(mx, arr[i]);
        suf[i] = mx;
    }
    long pre = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        pre = max(pre, arr[i]);
        ans += min(pre, suf[i]) - arr[i];
    }
    return ans;
}