#include <iostream>
#include <vector>
#include <queue>

using std::queue;
using std::vector;

void distance(vector<vector<int>> &adj, int s, vector<int> &dist, queue<int> q)
{
  dist[s] = 0;
  q.push(s);
  while (q.size() != 0)
  {
    int u = q.front();
    q.pop();
    for (size_t i = 0; i < adj[u].size(); i++)
    {
      if (dist[adj[u][i]] == -1)
      {
        q.push(adj[u][i]);
        dist[adj[u][i]] = dist[u] + 1;
      }
    }
  }
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n + 1, vector<int>());
  for (int i = 0; i < m; i++)
  {
    int x, y;
    std::cin >> x >> y;
    ()
        adj[x]
            .push_back(y);
    adj[y].push_back(x);
  }
  int s, t;
  std::cin >> s >> t;
  vector<int> dist(n + 1, -1);
  queue<int> q;
  distance(adj, s, dist, q);
  std::cout << dist[t];
}
