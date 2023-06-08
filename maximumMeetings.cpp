#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<vector<int>> v;
    int n = start.size();
    for(int i = 0; i < n; i++)
        v.push_back({start[i], end[i], i});
    sort(v.begin(), v.end(), [](const vector<int> &a, const vector<int> &b) {
        if (a[1] == b[1]) 
            return a[2] < b[2];
        return a[1] < b[1];
    });
    int prev = -1;
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        if(prev < v[i][0])
        {
            ans.push_back(v[i][2] + 1);
            prev = v[i][1];
        }
    }
    return ans;
}