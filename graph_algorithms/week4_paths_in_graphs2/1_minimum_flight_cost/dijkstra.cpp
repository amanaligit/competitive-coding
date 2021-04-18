#include <iostream>
#include <vector>
#include <queue>

using std::pair;
using std::priority_queue;
using std::queue;
using std::vector;
using namespace std;

int m;
long long max_cost = 0;
long long distance(vector<vector<int>> &adj, vector<vector<int>> &cost, int s, int t)
{
  vector<long long> dist(adj.size(), max_cost +1);
  vector<int> prev(adj.size());
  vector<bool> processed(adj.size(), false);
  dist[s] = 0;
  priority_queue<pair<long long, int>> pq;
  for (size_t i = 1; i < adj.size(); i++)
  {
    pq.push(make_pair(-dist[i], i));
  }
  while (!pq.empty())
  {
    pair<long long, int> u = pq.top();
    pq.pop();
    if (!processed[u.second])
    {
      for (size_t i = 0; i < adj[u.second].size(); i++)
      {
        if (dist[adj[u.second][i]] > dist[u.second] + cost[u.second][i])
        {
          dist[adj[u.second][i]] = dist[u.second] + cost[u.second][i];
          prev[adj[u.second][i]] = u.second;
          pq.push(make_pair(-dist[adj[u.second][i]], adj[u.second][i]));
        }
      }
      processed[u.second] = true;
    }
  }

  return dist[t]>=max_cost+1?-1:dist[t];
}

int main()
{
  int n;
  std::cin >> n >> m;
  vector<vector<int>> adj(n + 1, vector<int>());
  vector<vector<int>> cost(n + 1, vector<int>());
  for (int i = 0; i < m; i++)
  {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x].push_back(y);
    cost[x].push_back(w);
    max_cost += w;
  }
  int s, t;
  std::cin >> s >> t;
  // s--, t--;
  std::cout << distance(adj, cost, s, t);
}
