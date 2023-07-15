#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
	unordered_map<int, int> mp;
    vector<int> ans;
    for(int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
        if(i + 1 >= k)
        {
            ans.push_back(mp.size());
            mp[arr[i - k + 1]]--;
            if(mp[arr[i - k + 1]] == 0)
                mp.erase(arr[i - k + 1]);
        }
    }
    return ans;
}