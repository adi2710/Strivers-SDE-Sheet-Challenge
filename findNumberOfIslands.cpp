vector<int> dd = {-1, 0, 1};
void dfs(int r, int c, int **arr, int n, int m)
{
   arr[r][c] = 0;
   for(int i = 0; i < dd.size(); i++)
   {
      for(int j = 0; j < dd.size(); j++){
         if(dd[i] == 0 && dd[j] == 0)
            continue;
         int row = r + dd[i], col = c + dd[j];
         if(row < 0 || row >= n || col < 0 || col >= m || arr[row][col] == 0)
            continue;
         dfs(row, col, arr, n, m);
      }
   }
}

int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   int ans = 0;
   for(int r = 0; r < n; r++)
   {
      for(int c = 0; c < m; c++)
      {
         if(arr[r][c] == 1)
            dfs(r, c, arr, n, m), ans++;
      }
   }
   return ans;
}
