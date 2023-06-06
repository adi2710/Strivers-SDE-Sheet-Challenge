#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   unordered_map<int, int> mp;
   vector<vector<int>> ans;
   for(int x : arr)
   {
      if(mp.find(s - x) != mp.end())
      {
         int mn = min(x, s - x), mx = max(x, s - x);
         for(int i = 0; i < mp[s - x]; i++)
            ans.push_back({mn, mx});
      }
      mp[x]++;
   }
   sort(ans.begin(), ans.end());
   return ans;
}