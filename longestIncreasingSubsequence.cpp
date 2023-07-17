#include <vector>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        if(ans.empty() || ans.back() < arr[i])
            ans.push_back(arr[i]);
        else
        {
            int pos = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[pos] = arr[i];
        }
    }
    return ans.size();
}
