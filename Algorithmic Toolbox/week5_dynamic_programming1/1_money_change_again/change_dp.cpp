#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int get_change(int m, int* dp) {
  // for (size_t i = 0; i <= m; i++) {
  //   cout<<dp[i]<<" ";
  // }
  //cout<<endl;
  if(m==0) return 0;

  if(dp[m]!=INT_MAX) { return dp[m];}
  else
  {
      //cout<<"wow reached else with m = "<<m<<endl;
    if (m>= 3)
    {
            // cout<<"wow reached 3  "<<endl;
      int min_coin = 1+get_change(m-3, dp);
      dp[m] = min(min_coin, dp[m]);
    }
    if (m>= 4)
    {
      int min_coin = 1+get_change(m-4, dp);
      dp[m] = min(min_coin, dp[m]);
    }
    if (m>= 1)
    {
      int min_coin = 1+get_change(m-1, dp);
      dp[m] = min(min_coin, dp[m]);
    }

    return dp[m];

  }

}

int main() {
  int m;
  std::cin >> m;
  int dp[m+1];
  for (size_t i = 0; i <= m; i++) {
    dp[i]=INT_MAX;
    /* code */
  }

  std::cout << get_change(m, dp) << '\n';
}
