void reach(vector<vector<int>> &adj, int x, vector<bool> &marked)
{
    if (marked[x])
        return;
    marked[x] = true;
    for (size_t i = 0; i < adj[x].size(); i++)
    {
        reach(adj, adj[x][i], marked, id);
    }
}

vector<vector<int>> adj(n + 1, vector<int>());
for (size_t i = 0; i < m; i++)
{
    int x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}