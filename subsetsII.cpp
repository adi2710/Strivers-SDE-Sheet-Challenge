#include <bits/stdc++.h> 

void subset(int i, vector<int> &v, vector<int> &nums, vector<vector<int>> &ans)
{
    if(i == nums.size())
    {
        ans.push_back(v);
        return;
    }
    v.push_back(nums[i]);
    subset(i + 1, v, nums, ans);
    v.pop_back();
    while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
    subset(i + 1, v, nums, ans);
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> v;
    subset(0, v, arr, ans);
    sort(ans.begin(), ans.end());
    return ans;
}