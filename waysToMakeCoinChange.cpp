#include <algorithm>
long solve(int i, int value, int *denominations, int &n, vector<vector<long>> &dp)
{
    if(value == 0)
        return 1;
    if(i == n)
        return 0;
    if(dp[i][value] != -1)
        return dp[i][value];
    long ans = 0;
    for(int j = i; j < n; j++){
        if(value - denominations[j] >= 0)
            ans += solve(j, value - denominations[j], denominations, n, dp);
        else
            break;
    }
    return dp[i][value] = ans;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n, vector<long> (value + 1, -1));
    sort(denominations, denominations + n);
    return solve(0, value, denominations, n, dp);
}