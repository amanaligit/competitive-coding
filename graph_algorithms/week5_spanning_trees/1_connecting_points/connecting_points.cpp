#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <queue>
#include <iostream>
#include <climits>
using namespace std;

using std::vector;

double minimum_distance(vector<int> x, vector<int> y)
{
  double result = 0.;
  vector<double> cost(x.size(), INT_MAX);
  vector<bool> processed(x.size(), false);
  int i = 0;
  cost[i] = 0;
  priority_queue<pair<double, int>> pq;
  for (size_t i = 0; i < cost.size(); i++)
  {
    pq.push(make_pair(-cost[i], i));
  }
  while (!pq.empty())
  {
    int j = pq.top().second;
    pq.pop();

    if (!processed[j])
    {
      for (size_t i = 0; i < x.size(); i++)
      {
        if (i == j)
        {
          continue;
        }
        else
        {
          if (!processed[i] && cost[i] > sqrt(double((x[i] - x[j]) * (x[i] - x[j]) + ((y[i] - y[j]) * (y[i] - y[j])))))
          {
            cost[i] = sqrt(double((x[i] - x[j]) * (x[i] - x[j]) + ((y[i] - y[j]) * (y[i] - y[j]))));
            pq.push(make_pair(-cost[i], i));
          }
        }
      }
      processed[j] = true;
    }
  }
  for (size_t i = 0; i < cost.size(); i++)
  {
    result += cost[i];
  }

  return result;
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
