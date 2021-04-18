#include <iostream>
#include <cassert>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int bs(const vector<int> &a, int x, int left, int right)
{
  int mid = (int)(right + left) / 2;
  if (a[mid] == x)
    return mid;
  else if (left == right)
    return -1;
  else if (x < a[mid])
  {
    return bs(a, x, left, mid);
  }
  else if (x > a[mid])
  {
    return bs(a, x, mid + 1, right);
  }
}

int linear_search(const vector<int> &a, int x)
{
  for (size_t i = 0; i < a.size(); ++i)
  {
    if (a[i] == x)
      return i;
  }
  return -1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i)
  {
    std::cin >> b[i];
  }

  for (int i = 0; i < m; ++i)
  {
    //replace with the call to binary_search when implemented
    std::cout << bs(a, b[i], 0, a.size() - 1) << ' ';
  }
}
