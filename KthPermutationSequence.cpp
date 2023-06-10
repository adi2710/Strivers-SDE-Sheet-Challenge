string kthPermutation(int n, int k) {
    // Write your code here.
    k--;
    int fact = 1;
    vector<int> nums(n);
    for(int i = 1; i <= n; i++)
    {
        fact *= i;
        nums[i - 1] = i;
    }
    string ans;
    while(!nums.empty())
    {
        fact /= nums.size();
        int pos = k / fact;
        ans += to_string(nums[pos]);
        nums.erase(nums.begin() + pos);
        k %= fact;
    }
    return ans;
}