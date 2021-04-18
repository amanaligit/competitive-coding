#include <iostream>
#include <vector>
#include <algorithm>
#if defined(__unix__) || defined(__APPLE__)
#include <sys/resource.h>
#endif

using std::vector;
using std::ios_base;
using std::cin;
using std::cout;

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class TreeOrders {
  int n;
  vector <int> key;
  vector <int> left;
  vector <int> right;

public:
  void read() {
    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }
  }

  void in_order_rec(vector <int> &result, int i)
  {
    
    if(i==-1||right.size()==0) return;

    in_order_rec(result, left[i]);
    result.push_back(key[i]);
    in_order_rec(result, right[i]);
    return;
  }

  vector <int> in_order() {
    vector<int> result;
    in_order_rec(result, 0);

    


    // Finish the implementation
    // You may need to add a new recursive method to do that

    return result;
  }
  void pre_order_rec(vector <int> &result, int i)
  {
    
    if(i==-1) return;

    result.push_back(key[i]);
    pre_order_rec(result, left[i]);
    pre_order_rec(result, right[i]);
    return;
  }

  vector <int> pre_order() {
    vector<int> result;
    pre_order_rec(result, 0);
        
    // Finish the implementation
    // You may need to add a new recursive method to do that
    
    return result;
  }

  void post_order_rec(vector <int> &result, int i)
  {
    
    if(i==-1) return;

    
    post_order_rec(result, left[i]);
    post_order_rec(result, right[i]);
    result.push_back(key[i]);
    return;
  }

  vector <int> post_order() {
    vector<int> result;
    post_order_rec(result, 0);
    // Finish the implementation
    // You may need to add a new recursive method to do that
    
    return result;
  }


};

  void print(vector <int> a) {
  if(a.size()==0)
  {
          cout<<"CORRECT"<<endl; return;

  }
  for (size_t i = 0; i < a.size()-1; i++) {
    if(a[i]>a[i+1])
    {
      cout<<"INCORRECT"<<std::endl;
      return;
    }
 
  }
    cout<<"CORRECT"<<endl; return;
}










int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
  TreeOrders t;
  t.read();
  print(t.in_order());
  
  return 0;
}

// int main_with_large_stack_space() {
//   ios_base::sync_with_stdio(0);
//     int nodes;
//   cin >> nodes;
//   vector<Node> tree;
//   for (int i = 0; i < nodes; ++i) {
//     int key, left, right;
//     cin >> key >> left >> right;
//     tree.push_back(Node(key, left, right));
//   }
//   if (IsBinarySearchTree(tree)) {
//     cout << "CORRECT" << endl;
//   } else {
//     cout << "INCORRECT" << endl;
//   }
//   return 0;
// }

int main (int argc, char **argv)
{
#if defined(__unix__) || defined(__APPLE__)
  // Allow larger stack space
  const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
      if (rl.rlim_cur < kStackSize)
      {
          rl.rlim_cur = kStackSize;
          result = setrlimit(RLIMIT_STACK, &rl);
          if (result != 0)
          {
              std::cerr << "setrlimit returned result = " << result << std::endl;
          }
      }
  }
#endif

  return main_with_large_stack_space();
}

// int main() {
//   int nodes;
//   cin >> nodes;
//   vector<Node> tree;
//   for (int i = 0; i < nodes; ++i) {
//     int key, left, right;
//     cin >> key >> left >> right;
//     tree.push_back(Node(key, left, right));
//   }
//   if (IsBinarySearchTree(tree)) {
//     cout << "CORRECT" << endl;
//   } else {
//     cout << "INCORRECT" << endl;
//   }
//   return 0;
// }
