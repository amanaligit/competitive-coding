#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {


  if(a.size()%2==0)
  {
    for(int i=0; i<a.size()/2; i++)
    {
      if(a[i]==a[i+a.size()/2]){
        //cout<<i<<endl;
        return 1;

      }
    }
  }
  else{
    for(int i=0; i<=a.size()/2; i++)
    {
      if(a[i]==a[i+a.size()/2]){
        //cout<<i<<endl;
        return 1;

      }
    }

  }
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  sort(a.begin(), a.end());
  std::cout << get_majority_element(a, 0, a.size()) << '\n';
}
