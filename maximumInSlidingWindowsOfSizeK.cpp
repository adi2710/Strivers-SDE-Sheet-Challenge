#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    deque<int> dq;
    vector<int> ans;
    for(int i = 0; i < nums.size(); i++)
    {
        while(!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        dq.push_back(i);
        if(i + 1 >= k)
        {
            ans.push_back(nums[dq.front()]);
            if(dq.front() == i - k + 1)
                dq.pop_front();
        }
    }
    return ans;
}