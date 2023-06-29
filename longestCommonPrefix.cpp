string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans;
    for(int pos = 0; ; pos++)
    {
        if(pos > arr[0].size())
            return ans;
        for(int i = 1; i < n; i++)
        {
            if(pos > arr[i].size() || arr[i][pos] != arr[0][pos])
                return ans;
        }
        ans.push_back(arr[0][pos]);
    }
    return ans;
}


