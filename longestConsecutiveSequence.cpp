#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_set<int> st;
    for(int x : arr)
        st.insert(x);
    int ans = 0;
    for(int x : arr)
    {
        if(st.find(x - 1) == st.end())
        {
            int cnt = 0;
            for(int i = x; st.find(i) != st.end(); i++)
                cnt++;
            ans = max(ans, cnt);
        }
    }
    return ans;
}