#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using std::vector;

struct loot
{
  int weight;
  int value;
  double val_per_weight;
};

bool sort_loot(loot a, loot b)
{
  return a.val_per_weight>b.val_per_weight;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  loot l[weights.size()];
  double value= 0.0;
  for(int i=0; i<weights.size(); i++)
  {
    l[i].weight=weights[i];
    l[i].value=values[i];
    l[i].val_per_weight = ((double)values[i])/weights[i];
  }
  sort(l, l+weights.size(), sort_loot);
  //  for(int i=0; i<weights.size(); i++)
  //{
  //  cout<<l[i].weight<<" ";
//cout<<l[i].value<<" ";
  // cout<<l[i].val_per_weight<<" ";
  //}


  int i = 0;
  while(capacity!=0&&i<weights.size())
  {
    if(capacity>=l[i].weight)
    {
      value+=l[i].value;
      capacity-=l[i].weight;
    }
    else
    {
      value+=capacity*l[i].val_per_weight;
      capacity=0;
    }
    i++;
  }

  // write your code here

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
