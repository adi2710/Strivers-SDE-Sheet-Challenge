#include <bits/stdc++.h>

void partition(int i, vector<string> &sub, string &s,vector<vector<string>> &ans)
{
    if(i == s.size())
    {
        ans.push_back(sub);
        return;
    }
    for(int j = i; j < s.size(); j++)
    {
        bool isPalin = true;
        for(int k = i; k <= j; k++)
        {
            if(s[k] != s[j - k + i])
            {
                isPalin = false;
                break;
            }
        }
        if(isPalin)
        {
            sub.push_back(s.substr(i, j - i + 1));
            partition(j + 1, sub, s, ans);
            sub.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> sub;
    partition(0, sub, s, ans);
    return ans;
}