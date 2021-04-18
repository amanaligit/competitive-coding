#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool partition3(vector<int> &S, unordered_map <string, bool> &dp, int n, int a, int b, int c)
{
  string key = to_string(n)+"|"+to_string(a)+"|"+to_string(b)+"|"+to_string(c);
  if(a==0&&b==0&&c==0) return 1;
  if(n<0) return 0;

  if(dp.find(key)!=dp.end()) return dp[key];

  else
  {
    bool A = 0;
    if(a-S[n]>=0)
    A = partition3(S, dp, n-1, a-S[n], b, c);


    bool B = 0;
    if((!A)&&(b-S[n]>=0))
    B = partition3(S, dp, n-1, a, b-S[n], c);

    bool C = 0;
    if((!B)&&(!A)&&(c-S[n]>=0))
    C = partition3(S, dp, n-1, a, b, c-S[n]);

    dp[key] = A||B||C;
    // cout<<A<<B<<C<<endl;
    return dp[key];
  }
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  int sum = 0;
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
    sum+=A[i];
  }
  if(sum%3!=0)
  {
    cout<<0<<endl;
    return 0;
  }
  unordered_map <string, bool> lookup;


  std::cout << partition3(A, lookup, n-1 , sum/3, sum/3, sum/3) << '\n';
}
