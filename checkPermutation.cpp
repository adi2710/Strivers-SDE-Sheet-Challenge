#include <bits/stdc++.h> 
bool areAnagram(string &str1, string &str2){
    // Write your code here.
    if(str1.size() != str2.size())
        return false;
    unordered_map<char, int> mp;
    for(char ch : str1)
        mp[ch]++;
    for(char ch : str2)
    {
        mp[ch]--;
        if(mp[ch] == 0)
            mp.erase(ch);
    }
    return mp.empty();
}