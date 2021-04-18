#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int optimal_weight(int W, const vector<int> &w, vector <vector <int>> &dp, int i)
{

  if(W<=0||i<0) return 0;

  if(dp[W][i]!=-1) return dp[W][i];

  else
  {
    if(W-w[i]>=0) dp[W][i] = optimal_weight(W-w[i], w, dp, i-1)+w[i];
    dp[W][i] = max(dp[W][i], optimal_weight(W, w, dp, i-1));
    return dp[W][i];
  }

}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  vector <vector <int>> dp(W+1, vector <int> (n+1));
  for (size_t i = 0; i < dp.size(); i++) {
    for (size_t j = 0; j < dp[0].size(); j++) {
      dp[i][j]=-1;
    }
  }
  std::cout << optimal_weight(W, w, dp, n-1) << '\n';
}
