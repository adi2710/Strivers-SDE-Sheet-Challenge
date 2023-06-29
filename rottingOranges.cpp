#include <queue>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    int fresh = 0;
    queue<pair<int, int>> q;
    for(int r = 0; r < n; r++)
    {
        for(int c = 0; c < m; c++)
        {
            if(grid[r][c] == 2)
                q.push({r, c});
            else if(grid[r][c] == 1)
                fresh++;
        }
    }
    if(fresh == 0)
        return 0;
    int time = 0;
    vector<int> dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};
    while(!q.empty())
    {
        time++;
        for(int i = q.size(); i >= 1; i--)
        {
            auto pr = q.front();
            q.pop();
            int r = pr.first, c = pr.second;
            for(int j = 0; j < dr.size(); j++)
            {
                int row = r + dr[j], col = c + dc[j];
                if(row < 0 || row >= n || col < 0 || col >= m || grid[row][col] != 1)
                    continue;
                grid[row][col] = 2;
                q.push({row, col});
                fresh--;
            }
        }
        if(fresh == 0)
            return time;
    }
    return -1;
}