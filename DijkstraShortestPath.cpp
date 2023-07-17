#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &edges, int vertices, int e, int source) {
    // Write your code here.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<vector<pair<int, int>>> gr(vertices);
    for(auto &edge : edges)
    {
        gr[edge[0]].push_back({edge[1], edge[2]});
        gr[edge[1]].push_back({edge[0], edge[2]});
    }
    pq.push({0, source});
    vector<int> vis(vertices, INT_MAX);
    vis[0] = 0;
    while(!pq.empty())
    {
        auto cur = pq.top().second;
        pq.pop();
        for(auto adj : gr[cur]){
            if(vis[adj.first] > vis[cur] + adj.second)
            {
                vis[adj.first] = vis[cur] + adj.second;
                pq.push({vis[adj.first], adj.first});
            }
        }
    }
    return vis;
}