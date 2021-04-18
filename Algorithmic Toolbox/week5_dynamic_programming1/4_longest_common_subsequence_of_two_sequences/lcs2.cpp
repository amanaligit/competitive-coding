#include <iostream>
#include <vector>

using namespace std;

int lcs2(vector<int> &a, vector<int> &b, vector <vector <int>> &dp)
{
  for (size_t i = 0; i <= a.size(); i++) {
    dp[i][0] = 0;
  }
  for (size_t i = 0; i <= b.size(); i++) {
    dp[0][i] = 0;
  }

  for (size_t i = 1; i <= a.size(); i++)
  {
    for (size_t j = 1; j <= b.size(); j++)
    {
      int del = dp[i][j-1];
      int ins = dp[i-1][j];
      int match = dp[i-1][j-1]+1;
      int mis_match = dp[i-1][j-1];
      if(a[i-1]==b[j-1])
      {
        dp[i][j] =  max(max(del, ins), match );
      }
      else
      {
        dp[i][j] =  max(max(del, ins), mis_match );
      }
    }
  }
  return dp[a.size()][b.size()];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }
  vector <vector <int>> dp(a.size()+1, vector <int> (b.size()+1));
  std::cout << lcs2(a, b, dp) << std::endl;
}
