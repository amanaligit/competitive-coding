#include <iostream>
#include <vector>
#include <queue>

using std::queue;
using std::vector;

bool bipartite(vector<vector<int>> &adj, int s, queue<int> &q, vector<bool> &explored, vector <int> &colour)
{
  
  colour[s] = 0;
  q.push(s);
  explored[s] = true;
  while (q.size() != 0)
  {
    
    int u = q.front();
    q.pop();

    for (size_t i = 0; i < adj[u].size(); i++)
    {
      explored[adj[u][i]] = true;
      if (colour[adj[u][i]] == -1)
      {
  
        q.push(adj[u][i]);
        colour[adj[u][i]] = 1 - colour[u];
      }
      else if (colour[adj[u][i]] == colour[u])
      {
        
        return false;
      }
      // if(dist[adj[u][i]]==-1)
      // {
      //   q.push(adj[u][i]);
      //   prev[adj[u][i]]= ;
      // }
    }
  }
  return true;
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
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  queue<int> q;
  bool ans;
  vector<bool> explored(n + 1, 0);
  vector<int> colour(adj.size(), -1);
  for (size_t i = 1; i < adj.size(); i++)
  {
    if (!explored[i])
    {
      ans = bipartite(adj, i, q, explored, colour);
      if (ans == 0)
      {
        std::cout << ans;
        return 0;
      }
    }
  }

  std::cout << true;
}

// #include <iostream>

// #include <vector>
// #include <queue>

// using std::vector;
// using std::queue;

// int bipartite(vector<vector<int> > &adj) {
//   //write your code here
//   return -1;
// }

// int main() {
//   int n, m;
//   std::cin >> n >> m;
//   vector<vector<int> > adj(n, vector<int>());
//   for (int i = 0; i < m; i++) {
//     int x, y;
//     std::cin >> x >> y;
//     adj[x - 1].push_back(y - 1);
//     adj[y - 1].push_back(x - 1);
//   }
//   std::cout << bipartite(adj);
// }
