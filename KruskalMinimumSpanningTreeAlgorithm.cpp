#include <bits/stdc++.h>
int find(int cur, vector<int> &par)
{
	if(cur == par[cur])
		return cur;
	return par[cur] = find(par[cur], par);
}

bool unite(int u, int v, vector<int> &rank, vector<int> &par)
{
	int par_u = find(u, par), par_v = find(v, par);
	if(par_u == par_v)
		return false;
	if(rank[par_u] == rank[par_v])
	{
		par[par_v] = par_u;
		rank[par_u]++;
	}
	else if(rank[par_u] < rank[par_v])
		par[par_u] = par_v;
	else
		par[par_v] = par_u;
	return true;
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
	vector<int> rank(n + 1), par(n + 1);
	iota(par.begin(), par.end(), 0);
	sort(graph.begin(), graph.end(), [](const vector<int> &a, const vector<int> &b){
		return a[2] < b[2];
	});
	int ans = 0;
	for(auto edge : graph)
	{
		int u = edge[0], v = edge[1], wt = edge[2];
		if(unite(u, v, rank, par))
			ans += wt;
	}
	return ans;
}