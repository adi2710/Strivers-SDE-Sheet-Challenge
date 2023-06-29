#include <bits/stdc++.h> 
bool findPattern(string p, string s)
{
    // Write your code here.
    int n = s.size(), m = p.size();
    vector<int> lps(m);
    int i = 0, j = 1;
    while(j < m)
    {
        if(p[i] == p[j])
        {
            lps[j] = i + 1;
            i++, j++;
        }
        else
        {
            if(i == 0)
                j++;
            else
                i = lps[i - 1];
        }
    }
    i = 0, j = 0;
    while(i < n)
    {
        if (s[i] == p[j]) {
            i++, j++;
            if (j == m)
                return true;
        }
        else
        {
            if(j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
    return false;
}