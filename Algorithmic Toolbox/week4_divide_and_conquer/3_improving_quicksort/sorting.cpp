
#include <bits/stdc++.h>
using namespace std;


pair<int, int> partition2(vector<int> &a, int l, int r)
{
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++)
  {
    if (a[i] < x) {
      j++;
      swap(a[i], a[j]);
    }
    if (a[i] == x)
    {
      {
        j++;
        swap(a[i], a[l+1]);
        if(j!=l+1)
        swap(a[j], a[i]);
      }

    }
    //for (size_t i = 0; i < a.size(); ++i)
    //{
    //  std::cout << a[i] << ' ';
    //}      cout<<endl;
  }
  int right = j;
  while(a[l]==x&&l<j){

      swap(a[l++], a[j--]);
      //for (size_t i = 0; i < a.size(); ++i)
      {
        //std::cout << a[i] << ' ';

      }      cout<<endl;
  }
  //cout<<j+1<<" "<<right<<endl;
  return make_pair(j+1, right);
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);

  swap(a[l], a[k]);
  cout<<endl;
  //for (size_t i = 0; i < a.size(); ++i)
  //{
    //std::cout << a[i] << ' ';

  //}      cout<<endl;
  pair <int, int> p = partition2(a, l, r);


  randomized_quick_sort(a, l, p.first - 1);
  randomized_quick_sort(a, p.second + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cout << a[i] << ' ';
  }
}
