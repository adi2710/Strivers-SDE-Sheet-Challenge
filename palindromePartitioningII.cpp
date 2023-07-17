#include <bits/stdc++.h>
bool checkPalindrome(string &s)
{
    for(int l = 0, r = s.size() - 1; l < r; l++, r--)
    {
        if(s[l] != s[r])
            return false;
    }
    return true;
}
int solve(int i, string &s, vector<int> &dp)
{
    if(i == s.size())
        return 0;
    if(dp[i] != -1)
        return dp[i];
    int ans = INT_MAX;
    string sub;
    for(int j = i; j < s.size(); j++)
    {
        sub += s[j];
        if(checkPalindrome(sub))
            ans = min(ans, 1 + solve(j + 1, s, dp));
    }
    return dp[i] = ans;
}

int palindromePartitioning(string str) {
    // Write your code here
    vector<int> dp(str.size(), -1);
    return solve(0, str, dp) - 1;
}