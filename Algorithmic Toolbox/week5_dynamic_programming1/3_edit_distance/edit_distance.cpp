#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;
int n;
int edit_distance(const string &str1, const string &str2, vector <vector<int>> dp)
{
  for (size_t i = 0; i <= str1.size(); i++) {
    dp[i][0] = i;
  }
  for (size_t i = 0; i <= str2.size(); i++) {
    dp[0][i] = i;
  }

  for (size_t i = 1; i <= str1.size(); i++)
  {
    for (size_t j = 1; j <= str2.size(); j++)
    {
      int num_del = dp[i][j-1]+1;
      int num_ins = dp[i-1][j] +1;
      int match = dp[i-1][j-1];
      int mis_match = dp[i-1][j-1]+1;
      if(str1[i-1]==str2[j-1])
      {
        dp[i][j] =  min(min(num_del, num_ins), match );
      }
      else
      {
        dp[i][j] =  min(min(num_del, num_ins), mis_match );
      }
    }
  }
  return dp[str1.size()][str2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  vector <vector <int>> dp(str1.size()+1, vector <int> (str2.size()+1));
  n = str2.size();

  std::cout << edit_distance(str1, str2, dp) << std::endl;
  return 0;
}
