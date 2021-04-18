#include <iostream>
#include <vector>

using std::vector;
using std::pair;


void reach(vector<vector<int> > &adj, int x, vector <int> &marked, const int &id) {
  if(marked[x]) return;
  marked[x] = id;
  for (size_t i = 0; i < adj[x].size(); i++)
  {
    reach(adj, adj[x][i], marked, id);
  }
  
  
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n+1, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  // int x, y;
  // std::cin >> x >> y;
  vector <int> marked(n+1, 0);
  int id = 1;
  for (size_t i = 1; i <= n; i++)
  {
     if(!marked[i])
     {
       reach(adj, i, marked, id);
       id++;
     }

  }
  
 
  std::cout << id - 1<<std::endl;
}
