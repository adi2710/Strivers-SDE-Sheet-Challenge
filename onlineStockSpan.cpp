#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    stack<int> st;
    st.push(-1);
    vector<int> ans(price.size(), 1);
    for(int i = 0; i < price.size(); i++)
    {
        while(st.size() > 1 && price[st.top()] <= price[i])
            st.pop();
        ans[i] = i - st.top();
        st.push(i);
    }
    return ans;
}