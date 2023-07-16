bool dfs(int cur, int par, vector<bool> &vis, vector<vector<int>> &gr)
{
    vis[cur] = true;
    bool cycle = false;
    for(int adj : gr[cur])
    {
        if(adj == par)
            continue;
        if(vis[adj])
            return true;
        cycle = cycle || dfs(adj, cur, vis, gr);
    }
    return cycle;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<vector<int>> gr(n + 1);
    for(auto &edge : edges){
        gr[edge[0]].push_back(edge[1]);
        gr[edge[1]].push_back(edge[0]);
    }
    vector<bool> vis(n);
    bool ans = false;
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
            ans = ans || dfs(i, i, vis, gr);
    }
    return ans ? "Yes" : "No";
}