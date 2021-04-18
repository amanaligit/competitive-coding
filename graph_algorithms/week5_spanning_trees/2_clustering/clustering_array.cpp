#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>

using std::pair;
using std::vector;
using namespace std;

struct DisjointSetsElement
{
  int parent, rank;
  // pair<int, int> point;

  DisjointSetsElement(int parent = -1, int rank = 0) : parent(parent), rank(rank) {}
};

struct DisjointSets
{
  int size;
  int max_table_size;
  vector<DisjointSetsElement> sets;

  DisjointSets(int size) : size(size), max_table_size(0), sets(size)
  {
    for (int i = 0; i < size; i++)
    {
      sets[i].parent = i;
      // sets[i].point = make_pair(x[i], y[i]);
    }
  }

  int getParent(int table)
  {
    if (table != sets[table].parent)
      sets[table].parent = getParent(sets[table].parent);
    return sets[table].parent;
    // find parent and compress path
  }

  void merge(int destination, int source)
  {
    int realDestination = getParent(destination);
    int realSource = getParent(source);
    if (realDestination != realSource)
    {
      // merge two components
      // use union by rank heuristic
      // update max_table_size
      if (sets[realDestination].rank > sets[realSource].rank)
      {
        sets[realSource].parent = realDestination;
        // sets[realDestination].size += sets[realSource].size;
        // sets[realSource].size = 0;
      }

      else
      {
        sets[realDestination].parent = realSource;
        // sets[realSource].size += sets[realDestination].size;
        // sets[realDestination].size = 0;
        if (sets[realDestination].rank == sets[realSource].rank)
        {
          sets[realSource].rank = sets[realSource].rank + 1;
        }
      }
      // cout<<sets[realSource].size<<sets[realDestination].size<<std::endl;
      // max_table_size = max(max_table_size, max(sets[realSource].size, sets[realDestination].size));
    }
  }
};

double clustering(vector<int> x, vector<int> y, int k)
{

  DisjointSets points(x.size());
  int num_clusters = x.size();
  vector<pair<double, pair<int, int>>> distances;
  for (size_t i = 0; i < x.size(); i++)
  {
    for (size_t j = 0; j < x.size(); j++)
    {
      if (i != j)
      {
        distances.push_back(make_pair(sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])), make_pair(i, j)));
      }

      // = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    }
  }
  // for (size_t i = 0; i < distances.size(); i++)
  // {
  //   cout<<distances[i].first<<endl;
  // }
  
  sort(distances.begin(), distances.end());
  pair<double, pair<int, int>> ans;

  int i;
  for (i = 0; i < distances.size(); i++)
  {
    if (points.getParent(distances[i].second.first) != points.getParent(distances[i].second.second))
    {
      points.merge(distances[i].second.first, distances[i].second.second);
      // ans = distances[i + 1];
      num_clusters--;
      if (num_clusters <= k)
      {
        break;
      }
    }
  }

  for (size_t j = i; j < distances.size(); j++)
  {
    if (points.getParent(distances[j].second.first) != points.getParent(distances[j].second.second))
    {
      ans = distances[j];
      break;
    }
  }

  return ans.first;
}

int main()
{
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> x[i] >> y[i];
  }

  std::cin >> k;
  std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
}
