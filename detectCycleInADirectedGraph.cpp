bool dfs(int cur, vector<int> &vis, vector<vector<int>> &gr)
{
  vis[cur] = 1;
  bool cycle = false;
  for(int adj : gr[cur])
  {
    if(vis[adj] == 2)
      continue;
    if (vis[adj] == 1)
      return true;
    cycle = cycle || dfs(adj, vis, gr);
  }
  vis[cur] = 2;
  return cycle;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  vector<vector<int>> gr(n + 1);
    for(auto &edge : edges)
        gr[edge.first].push_back(edge.second);
    vector<int> vis(n + 1);
    bool ans = false;
    for(int i = 1; i <= n; i++)
    {
      if(!vis[i])
        ans = ans || dfs(i, vis, gr);
    }
    return ans;
}