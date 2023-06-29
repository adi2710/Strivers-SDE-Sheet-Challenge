#include <bits/stdc++.h> 
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    stack<int> st;
    st.push(-1);
    a.push_back(INT_MIN);
    vector<int> ans(n, INT_MIN);
    for(int i = 0; i < a.size(); i++)
    {
        while(st.size() > 1 && a[st.top()] >= a[i])
        {
            int num = a[st.top()];
            st.pop();
            int len = i - st.top() - 1;
            ans[len - 1] = max(ans[len - 1], num);
        }
        st.push(i);
    }
    for(int i = n - 2; i >= 0; i--)
        ans[i] = max(ans[i], ans[i + 1]);
    return ans;
}