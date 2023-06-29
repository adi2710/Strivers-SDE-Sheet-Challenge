#include <bits/stdc++.h> 
int romanToInt(string s) {
    // Write your code here
    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int n = s.size(), ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(i + 1 < n && mp[s[i + 1]] > mp[s[i]])
            ans += mp[s[i + 1]] - mp[s[i]], i++;
        else
            ans += mp[s[i]];
    }
    return ans;
}
