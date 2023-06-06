#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int X)
{
    //    Write your code here.
    int sum = 0, ans = 0;
    unordered_map<int, int> mp;
    mp[0]++;
    for(int x : arr)
    {
        sum ^= x;
        if(mp.find(sum ^ X) != mp.end())
            ans += mp[sum ^ X];
        mp[sum]++;
    }
    return ans;
}