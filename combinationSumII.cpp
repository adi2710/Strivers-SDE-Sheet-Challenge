#include <bits/stdc++.h>
void subset(int i, vector<int> &v, int &k, vector<int> &nums, vector<vector<int>> &ans)
{
    if(i == nums.size())
    {
        int sum = accumulate(v.begin(), v.end(), 0);
        if(sum == k)
            ans.push_back(v);
        return;
    }
    v.push_back(nums[i]);
    subset(i + 1, v, k, nums, ans);
    v.pop_back();
	while(i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
    subset(i + 1, v, k, nums, ans);
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
	sort(arr.begin(), arr.end());
	vector<int> v;
    vector<vector<int>> ans;
    subset(0, v, target, arr, ans);
	sort(ans.begin(), ans.end());
	return ans;
}
