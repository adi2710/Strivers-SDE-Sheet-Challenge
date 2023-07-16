bool dfs(int cur, vector<int> &col, vector<vector<int>> &edges)
{
	bool fl = false;
	for(int j = 0; j < edges.size(); j++)
	{
		int adj = j;
		if(edges[cur][adj] == 0)
			continue;
		if(col[adj] == col[cur])
			return true;
		col[adj] = 3 - col[cur];
		fl = fl || dfs(adj, col, edges); 
	}
	return fl;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int n = edges.size();
	vector<int> col(n);
	bool ans = false;
	for(int i = 0; i < edges.size(); i++)
	{
		if(!col[i])
		{
			col[i] = 1;
			ans = ans || dfs(i, col, edges);
		}
	}
	return !ans;
}