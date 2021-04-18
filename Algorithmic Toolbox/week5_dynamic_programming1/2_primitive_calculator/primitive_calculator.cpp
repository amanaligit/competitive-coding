#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// vector<int> optimal_sequence(int n) {
//   std::vector<int> sequence;
//   while (n >= 1) {
//     sequence.push_back(n);
//     if (n % 3 == 0) {
//       n /= 3;
//     } else if (n % 2 == 0) {
//       n /= 2;
//     } else {
//       n = n - 1;
//     }
//   }
//   reverse(sequence.begin(), sequence.end());
//   return sequence;
// }

// vector<int> optimal_sequence(int n, vector<vector<int>> &dp) {
//   vector <int> seq;
//   cout<<n<<endl;
//   if(dp[n].size()>0) return dp[n];
//
//   if(n==0) return seq;
//
//   else
//   {
//     if(n-1>=0)
//     {
//         seq = optimal_sequence(n-1, dp);
//         if(dp[n].size()==0||dp[n].size()>seq.size()+1)
//         {
//           seq.push_back(n);
//           dp[n] = seq;
//         }
//     }
//     if(n%2==0)
//     {
//         seq = optimal_sequence(n/2, dp);
//         if(dp[n].size()==0||dp[n].size()>seq.size()+1)
//         {
//           seq.push_back(n);
//           dp[n] = seq;
//         }
//     }
//     if(n%3==0)
//     {
//         seq = optimal_sequence(n/3, dp);
//         if(dp[n].size()==0||dp[n].size()>seq.size()+1)
//         {
//           seq.push_back(n);
//           dp[n] = seq;
//         }
//     }
//     return dp[n];
//   }
// }

vector<int> optimal_sequence(int n, vector<vector<int>> &dp) {
  vector <int> seq;
  // cout<<n<<endl;
  // if(dp[n].size()>0) return dp[n];
  //
  // if(n==0) return seq;

  for(int i=1; i<=n; i++)
  {
    if(i-1>=0)
    {
        seq = dp[i-1];
        seq.push_back(i);
        dp[i] = seq;

    }
    if(i%2==0)
    {
      seq = dp[i/2];
      seq.push_back(i);
      if(dp[i].size()>seq.size()) dp[i] = seq;
    }
    if(i%3==0)
    {
      seq = dp[i/3];
      seq.push_back(i);
      if(dp[i].size()>seq.size()) dp[i] = seq;
    }
  }
  return dp[n];
}



int main() {
  int n;
  std::cin >> n;
  vector<vector <int>> dp(n+1);
  vector<int> sequence = optimal_sequence(n, dp);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
