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

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

bool left_correct(const vector<Node>& tree, int i)
{
  if(i==-1) return 1;
  
  bool ans = 1;
  ans = (tree[tree[i].left].key<tree[i].key)||tree[i].left==-1;
  if(ans==0) return ans;
  ans = ((tree[tree[i].right].key>tree[i].key)&&(tree[tree[i].right].key<tree[0].key))||tree[i].right==-1;
  if(ans==0) return ans;
  ans = left_correct(tree, tree[i].left);
  if(ans==0) return ans;
  ans = left_correct(tree, tree[i].right);

  return ans;

}

bool right_correct(const vector<Node>& tree, int i)
{
  if(i==-1) return 1;
  
  bool ans = 1;
  ans = (tree[tree[i].left].key<tree[i].key)&&(tree[tree[i].left].key>tree[0].key)||tree[i].left==-1;
  if(ans==0) return ans;
  ans = (tree[tree[i].right].key>tree[i].key)||tree[i].right==-1;
  if(ans==0) return ans;
  ans = right_correct(tree, tree[i].left);
  if(ans==0) return ans;
  ans = right_correct(tree, tree[i].right);

  return ans;

}



// bool right_correct(const vector<Node>& tree)
// {
//   bool ans = 0;
//   int i = tree[0].key;
//   while(i!=-1)
//   {
//     ans = (tree[tree[i].left].key<tree[i].key)&&((tree[tree[i].right].key>tree[i].key)&&(tree[tree[i].right].key>tree[0].key));
//     i = tree[i].right;
//   }
//   return ans;
// }



bool IsBinarySearchTree(const vector<Node>& tree) {
  bool ans = 1;
  if(tree.size()==0||tree.size()==1) return 1;
  if(tree[tree[0].left].key>tree[0].key&&tree[0].left!=-1) return 0;
  ans = left_correct(tree, tree[0].left);

  if(tree[tree[0].right].key<tree[0].key&&tree[0].right!=-1) return 0;
  ans = right_correct(tree, tree[0].right)&&ans;

  // Implement correct algorithm here
  return ans;
}


int main_with_large_stack_space() {
  ios_base::sync_with_stdio(0);
    int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}

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
