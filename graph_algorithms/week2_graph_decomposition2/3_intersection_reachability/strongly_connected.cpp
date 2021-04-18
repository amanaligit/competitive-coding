#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::pair;
using namespace std;

int clock_ = 0;
int scc = 0;

void reach(vector<vector<int> > &adj,  int x, vector <bool> &deleted, vector<bool> &marked) {
  if(marked[x]) return;
  marked[x] = 1;

  bool ans = 1;

  for (size_t i = 0; i < adj[x].size(); i++)
  {
    if(!deleted[adj[x][i]])
    {
        reach(adj, adj[x][i], deleted, marked);
    }

    
  }

  deleted[x] = 1;

  return;
  
  
}
void post_order(vector<vector<int> > &radj,  int x, vector<bool> &marked, vector<pair<int, int>> &post) {
  if(marked[x]) return;
  marked[x] = 1;
  clock_++;

  bool ans = 1;

  for (size_t i = 0; i < radj[x].size(); i++)
  {
    // if(!deleted[adj[x][i]])
    {
        post_order(radj, radj[x][i],marked, post);
    }

    
  }

    post.push_back(make_pair(clock_++, x));

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
    radj[y].push_back(x);
  }
  vector<pair<int, int>> post;
  for (size_t i = 1; i <= n; i++)
  {
    post_order(radj, i, marked, post);
  }

  sort(post.begin(), post.end());
  
  vector<bool> marked1 (n+1, 0);
  for (int i = post.size() - 1; i >= 0; i--)
  {
    if(!marked1[post[i].second])
    {
        if(!deleted[post[i].second])
        {
            reach(adj, post[i].second, deleted, marked1);
            scc++;
        }
    }
  }

  cout<<scc<<endl;
  




  


  
  


  
 
  
    // reach(adj, 0, deleted, marked, output);
  
}
