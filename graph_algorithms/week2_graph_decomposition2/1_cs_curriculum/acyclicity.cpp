#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

using std::vector;
using std::pair;
using namespace std;

bool reach(vector<vector<int> > &adj, int x, vector <bool> &deleted, vector<bool> &marked) {
  if(marked[x]) return false;
  marked[x] = 1;

  bool ans = 1;

  for (size_t i = 0; i < adj[x].size(); i++)
  {
    if(!deleted[adj[x][i]])
    {
        ans = ans&&reach(adj, adj[x][i], deleted, marked);
    }

    
  }
  deleted[x] = 1;
  return ans;
  
  
}

int main() {
  size_t n, m;
  std::cin >> n >> m;


  vector<vector<int> > adj(n+1, vector<int>());
  vector<bool> deleted (n+1, 0);
  vector<bool> marked (n+1, 0);
  
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
  }
 
  bool ans = 1;
  for (size_t i = 1; i <= n; i++)
  {
    if(!deleted[i])
    {
        ans = ans&&reach(adj, i, deleted, marked);
    }
    
  }
  cout<<!ans<<endl;
}
