#include <bits/stdc++.h>

int solve(int l, int r, vector<int> &arr, vector<vector<int>> &dp)
{
    if(l > r)
        return 0;
    if(dp[l][r] != -1)
        return dp[l][r];
    int ans = INT_MAX;
    for(int mid = l; mid <= r; mid++)
        ans = min(ans, arr[l - 1] * arr[mid] * arr[r + 1] + solve(l, mid - 1, arr, dp) + solve(mid + 1, r, arr, dp));
    return dp[l][r] = ans;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N, vector<int> (N, -1));
    return solve(1, N - 2, arr, dp);
}