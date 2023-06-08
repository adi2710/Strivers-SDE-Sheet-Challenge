#include <bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<vector<int>> v;
    for(int i = 0; i < start.size(); i++)
        v.push_back({start[i], finish[i]});
    sort(v.begin(), v.end(), [](const vector<int> &a, const vector<int> &b){
        if(a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1];
    });
    int ans = 0, prev = -1;
    for(auto &x : v)
    {
        if(prev <= x[0])
        {
            ans++;
            prev = x[1];
        }
    }
    return ans;
}