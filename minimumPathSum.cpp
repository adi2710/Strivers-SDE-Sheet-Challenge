#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int> (m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i == 0 && j == 0)
                dp[i][j] = grid[i][j];
            else if(i == 0)
                dp[i][j] = grid[i][j] + dp[i][j - 1];
            else if(j == 0)
                dp[i][j] = grid[i][j] + dp[i - 1][j];
            else
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n - 1][m - 1];
}