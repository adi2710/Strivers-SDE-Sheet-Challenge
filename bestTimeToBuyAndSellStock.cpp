#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int mn = INT_MAX, profit = 0;
    for(int x : prices)
    {
        mn = min(mn, x);
        profit = max(profit, x - mn);
    }
    return profit;
}