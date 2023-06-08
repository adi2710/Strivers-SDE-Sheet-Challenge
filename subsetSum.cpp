#include <bits/stdc++.h>

void subset(int i, int sum, vector<int> &nums, vector<int> &ans)
{
    if(i == nums.size())
    {
        ans.push_back(sum);
        return;
    }
    subset(i + 1, sum, nums, ans);
    subset(i + 1, sum + nums[i], nums, ans);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> ans;
    subset(0, 0, num, ans);
    sort(ans.begin(), ans.end());
    return ans;
}