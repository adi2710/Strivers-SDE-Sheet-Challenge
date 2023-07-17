int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    n++;
    vector<vector<int>> gr(n, vector<int> (n, 1e9));
    for(auto &edge : edges)
        gr[edge[0]][edge[1]] = edge[2];
    for(int i = 0; i < n; i++)
        gr[i][i] = 0;
    for(int k = 0; k < n; k++)    
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(max(gr[i][k], gr[k][j]) < 1e9 && gr[i][k] + gr[k][j] < gr[i][j])
                    gr[i][j] = gr[i][k] + gr[k][j];
            }
        }
    }
    return gr[src][dest];
}