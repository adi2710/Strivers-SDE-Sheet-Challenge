#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int> deno = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int pos = deno.size() - 1, ans = 0;
    while(amount)
    {
        ans += amount / deno[pos];
        amount %= deno[pos];
        pos--;
    }
    return ans;
}
