#include <bits/stdc++.h> 
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), [](const pair<int, int> &a, const pair<int, int> &b){
        return a.second * b.first > b.second * a.first;
    });
    int wt = 0;
    double ans = 0;
    for(auto x : items)
    {
        if(wt + x.first <= w)
            ans += x.second, wt += x.first;
        else
        {
            int rem = w - wt;
            ans += 1.0 * x.second * rem / x.first;
            break;
        }
    }
    return ans;
}