#include <stack>
void dfs(int cur, vector<bool> &vis, stack<int> &st, vector<vector<int>> &gr)
{
    vis[cur] = true;
    for(int adj : gr[cur])
    {
        if(!vis[adj])
            dfs(adj, vis, st, gr);
    }
    st.push(cur);
}

void dfs2(int cur, vector<bool> &vis, vector<vector<int>> &ans, vector<vector<int>> &revGr)
{
    vis[cur] = true;
    ans.back().push_back(cur);
    for(int adj : revGr[cur])
    {
        if(!vis[adj])
            dfs2(adj, vis, ans, revGr);
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<int>> gr(n), revGr(n);
    for(auto &edge : edges)
    {
        gr[edge[0]].push_back(edge[1]);
        revGr[edge[1]].push_back(edge[0]);
    }
    stack<int> st;
    vector<bool> vis(n), vis1(n);
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
            dfs(i, vis, st, gr);
    }
    
    vector<vector<int>> ans;
    while(!st.empty())
    {
        int cur = st.top();
        st.pop();
        if(!vis1[cur])
        {
            ans.push_back({});
            dfs2(cur, vis1, ans, revGr);
        }
    }
    return ans;
}