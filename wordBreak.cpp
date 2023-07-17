#include <bits/stdc++.h> 
bool solve(int i, string &s, unordered_set<string> &st, vector<int> &dp)
{
    if(i == s.size())
        return true;
    if(dp[i] != -1)
        return dp[i];
    bool ans = false;
    string sub;
    for(int j = i; j < s.size(); j++)
    {
        sub += s[j];
        if(st.find(sub) != st.end())
            ans = ans || solve(j + 1, s, st, dp);
    }
    return dp[i] = ans;
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    // Write your code here.
    unordered_set<string> st(arr.begin(), arr.end());
    vector<int> dp(target.size(), -1);
    return solve(0, target, st, dp);
}