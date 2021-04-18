#include <iostream>
#include <vector>

using std::vector;
using namespace std;


int negative_cycle(vector<vector<int>> &adj, vector<vector<int>> &cost)
{
  vector<long long> dist(adj.size());
  vector<int> prev(adj.size());
  // vector<bool> processed(adj.size(), false);

  for (size_t i = 0; i < adj.size() - 1; i++)
  {
    for (size_t i = 1; i < adj.size(); i++)
    {
      for (size_t j = 0; j < adj[i].size(); j++)
      {
        if (dist[adj[i][j]] > dist[i] + cost[i][j])
        {
          dist[adj[i][j]] = dist[i] + cost[i][j];
          prev[adj[i][j]] = i;
        }
      }
    }
  }
  vector<long long> next_dist = dist;
  for (size_t i = 1; i < adj.size(); i++)
  {
    for (size_t j = 0; j < adj[i].size(); j++)
    {
      if (next_dist[adj[i][j]] > next_dist[i] + cost[i][j])
      {
        next_dist[adj[i][j]] = next_dist[i] + cost[i][j];
        prev[adj[i][j]] = i;
      }
    }
  }
  return dist!=next_dist;
}


int main()
{
  int n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n+1, vector<int>());
  vector<vector<int>> cost(n+1, vector<int>());
  for (int i = 0; i < m; i++)
  {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x].push_back(y);
    cost[x].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
