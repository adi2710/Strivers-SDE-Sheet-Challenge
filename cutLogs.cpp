#include <climits>
#include <vector>
int solve(int n, int k, vector<vector<int>> &dp)
{
    if(n <= 1)
        return n;
    if(k == 1)
        return n;
    if(dp[n][k] != -1)
        return dp[n][k];
    int ans = INT_MAX, low = 1, high = n;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        int broken = solve(mid - 1, k - 1, dp);
        int not_broken = solve(n - mid, k, dp);
        ans = min(ans, 1 + max(broken, not_broken));
        if(broken < not_broken)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return dp[n][k] = ans;
}

int cutLogs(int k, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n + 1, vector<int> (k + 1, -1));
    return solve(n, k, dp);
}