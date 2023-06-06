#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long>> ans(n);
  ans[0].push_back(1);
  for(int r = 1; r < n; r++)
  {
    ans[r].push_back(1);
    for(int c = 1; c < r; c++)
      ans[r].push_back(ans[r - 1][c - 1] + ans[r - 1][c]);
    ans[r].push_back(1);
  }
  return ans;
}
