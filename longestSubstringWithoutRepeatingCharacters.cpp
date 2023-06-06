#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    unordered_map<char, int> mp;
    int ans = 0;
    for(int i = 0, j = 0; i < input.size(); i++)
    {
        if(mp.find(input[i]) != mp.end())
        {
            int pos = mp[input[i]];
            while(j <= pos)
                mp.erase(mp[j++]);
        }
        mp[input[i]] = i;
        ans = max(ans, i - j + 1);
    }
    return ans;
}