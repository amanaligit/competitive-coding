#include <iostream>
#include <vector>
using namespace std;

long long get_fibonacci_huge(long long n, int m) {
    // write your code here
    if (n <= 1)
        return n;


    vector <int> modfib;

    modfib.push_back(0);

    modfib.push_back(1);
    int i = 2;
    while(1)
    {

      modfib.push_back((modfib[i-1] + modfib[i-2])%m);
          //cout<<fib[i]<<", "<< modfib[i]<<endl;
      if(i==n) return modfib[i];
      if(modfib[i]==1&&modfib[i-1]==0)
      {
        modfib.pop_back();
        modfib.pop_back();
        break;
      }
      i++;
    }
    //cout<< modfib.size()<<endl;

    return modfib[(n%modfib.size())];
}
int main() {
    long long n;
    int m;
    cin >> n >> m;
    cout << get_fibonacci_huge(n, m) << '\n';
}
