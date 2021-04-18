#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector <int> factorize(int a)
{
  int num = a;
  int i = 2;
  vector<int> fact(1000007 ,0);
  while(num!=1)
  {
    while(num%i==0)
    {
      num/=i;
      fact[i]++;
    }
    i++;
  }
  return fact;
}

long long lcm(int a, int b)
{
  vector<int> fact_a = factorize(a);
  vector<int> fact_b = factorize(b);
  int n = max(a, b) ;
  vector<int> fact_common(n);

  for(int i =0; i<n; i++)
  {
    fact_common[i] = max(fact_a[i], fact_b[i]);
  }
  long long lcm = 1;
  for(int i=0; i<fact_common.size(); i++)
  {
    if(fact_common[i]!=0)
    lcm*= pow(i, fact_common[i]);
  }
  return lcm;

}



int main() {
  int a, b;
  cin >> a >> b;
  //vector<int> fact = factorize(10);
  //for(int i=0; i< fact.size(); i++)
  {
  //    cout << i<<", "<< fact[i] << endl;
  }
  cout << lcm(a,b) << endl;
  return 0;
}
