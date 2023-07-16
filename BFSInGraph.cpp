#include <bits/stdc++.h> 
vector<int> BFS(int V, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<vector<int>> gr(V);
    for(auto edge : edges)
    {
        gr[edge.first].push_back(edge.second);
        gr[edge.second].push_back(edge.first);
    }
    vector<int> ans;
    vector<bool> vis(V);
    for(auto &x : gr)
        sort(x.begin(), x.end());
    queue<int> q;
    for(int i = 0; i < V; i++){
        if(vis[i])
            continue;
        q.push(i);
        vis[i] = true;
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            for(int adj : gr[cur])
            {
                if(!vis[adj])
                    q.push(adj), vis[adj] = true;
            }
        }
    }
    return ans;
}