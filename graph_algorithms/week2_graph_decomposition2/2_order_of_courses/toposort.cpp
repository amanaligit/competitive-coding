#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

using std::vector;
using std::pair;
using namespace std;

void reach(vector<vector<int> > &adj,  int x, vector <bool> &deleted, vector<bool> &marked, vector<int> &output) {
  if(marked[x]) return;
  marked[x] = 1;

  bool ans = 1;

  for (size_t i = 0; i < adj[x].size(); i++)
  {
    if(!deleted[adj[x][i]])
    {
        reach(adj, adj[x][i], deleted, marked, output);
    }

    
  }

  deleted[x] = 1;
  output.push_back(x);

  return;
  
  
}

int main() {
  size_t n, m;
  std::cin >> n >> m;


  vector<vector<int> > adj(n+1, vector<int>());
  vector<vector<int> > radj(n+1, vector<int>());
  vector<bool> deleted (n+1, 0);
  vector<bool> marked (n+1, 0);
  
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
    // radj[y].push_back(x);
  }
  vector<int> output;
  
  for (size_t i = 1; i <= n; i++)
  {
    if(!marked[i])
    {
        if(!deleted[i])
        {
            reach(adj, i, deleted, marked, output);
        }
    }
  }
  for (int i = output.size() - 1; i >= 0; i--)
  {
    cout<<output[i]<<" ";
  }
  cout<<endl;
  
    // reach(adj, 0, deleted, marked, output);
  
}
