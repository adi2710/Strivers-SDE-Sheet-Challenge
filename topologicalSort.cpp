#include <bits/stdc++.h> 

void dfs(int cur, vector<bool> &vis, vector<int> &topo, vector<vector<int>> &gr)
{
    vis[cur] = true;
    for(int adj : gr[cur])
    {
        if(!vis[adj])
            dfs(adj, vis, topo, gr);
    }
    topo.push_back(cur);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int V, int e)  {
    // Write your code here
     vector<vector<int>> gr(V);
    for(auto &edge : edges)
        gr[edge[0]].push_back(edge[1]);
    vector<int> topo;
    vector<bool> vis(V);
    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
            dfs(i, vis, topo, gr);
    }
    reverse(topo.begin(), topo.end());
    return topo;
}