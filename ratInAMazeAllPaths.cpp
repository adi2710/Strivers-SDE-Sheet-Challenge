#include <bits/stdc++.h> 

vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

void solve(int r, int c, vector<int> &v, vector<vector<int>> &ans, vector<vector<int>> &maze)
{
  if(r < 0 || r >= maze.size() || c < 0 || c >= maze.size() || maze[r][c] == 0)
    return;
  if(r == maze.size() - 1 && c == maze.size() - 1)
  {
    v[r * maze.size() + c] = 1;
    ans.push_back(v);
    v[r * maze.size() + c] = 0;
    return;
  }
  maze[r][c] = 0;
  v[r * maze.size() + c] = 1;
  for(int i = 0; i < dx.size(); i++)
    solve(r + dx[i], c + dy[i], v, ans, maze);
  maze[r][c] = 1;
  v[r * maze.size() + c] = 0;
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
  vector<int> v(maze.size() * maze.size());
  vector<vector<int>> ans;
  solve(0, 0, v, ans, maze);
  sort(ans.begin(), ans.end());
  return ans;
}