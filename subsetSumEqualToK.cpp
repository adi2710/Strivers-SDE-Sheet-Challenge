#include <bits/stdc++.h> 

bool check(int i, int k, vector<int> &ar, vector<vector<int>> &dp)
{
    if(k == 0)
        return true;
    if(i == ar.size())
        return false;
    if(dp[i][k] != -1)
        return dp[i][k];
    bool skip = check(i + 1, k, ar, dp), take = false;
    if(k - ar[i] >= 0)
        take = check(i + 1, k - ar[i], ar, dp);
    return dp[i][k] = take || skip;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int> (k + 1, -1));
    return check(0, k, arr, dp);
}