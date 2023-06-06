#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int num1 = 0, num2 = 0, cnt1 = 0, cnt2 = 0;
    for(int x : arr)
    {
        if(x == num1) cnt1++;
        else if(x == num2) cnt2++;
        else if(cnt1 == 0) num1 = x, cnt1++;
        else if(cnt2 == 0) num2 = x, cnt2++;
        else
            cnt1--, cnt2--;
    }
    cnt1 = cnt2 = 0;
    for(int x : arr)
    {
        if(num1 == x)
            cnt1++;
        else if(num2 == x)
            cnt2++;
    }
    vector<int> ans;
    if(cnt1 > arr.size() / 3)
        ans.push_back(num1);
    if(cnt2 > arr.size() / 3)
        ans.push_back(num2);
    return ans;
}