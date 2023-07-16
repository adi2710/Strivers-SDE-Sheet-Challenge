void dfs(int cur,  vector<bool> &vis, vector<vector<int>> &gr, vector<int> &comp)
{
    vis[cur] = true;
    comp.push_back(cur);
    for(int adj : gr[cur])
    {
        if(!vis[adj])
            dfs(adj, vis, gr, comp);
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> gr(V);
    for(auto edge : edges)
    {
        gr[edge[0]].push_back(edge[1]);
        gr[edge[1]].push_back(edge[0]);
    }
    vector<vector<int>> ans;
    vector<bool> vis(V);
    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
        {
            vector<int> comp;
            dfs(i, vis, gr, comp);
            ans.push_back(comp);
        }
    }
    return ans;
}