#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;
int n = 0;
int max_num;

int first_check = 1;
int compute_min_refills(int dist, int tank, int*  stops) {
    // write your code here
    if(first_check)
    {
      for (int i=0; i<n-1; i++)
      {

        if(stops[i+1]-stops[i]>tank)
        {
          return -1;
        }
      }
      if(dist-stops[n-1]>tank) return -1;
      if (dist<=tank) return 0;
      first_check = 0;
    }

    int i;
    for(i=0; i<n; i++)
    {
      int temp = stops[i] - stops[0];
      if (temp> tank||stops[i]==max_num) break;
    }
    if (stops[i-1] + tank >= dist||i==n-1) return 1;
    else
    {
        return 1+compute_min_refills(dist, tank, stops+i-1);
    }

}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    cin >> n;
    n++;

    int stops[n];
    stops[0] = 0;
    for (size_t i = 1; i < n; ++i)
        cin >> stops[i];
    max_num = stops[n-1];

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
