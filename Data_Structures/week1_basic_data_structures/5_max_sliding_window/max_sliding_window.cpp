#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using namespace std;


class StackWithMax {
    stack <int> s1, s2;

  public:

    void push(int value) {
        s1.push(value);
        if(s1.size()==1)
        {
          s2.push(value);
        }
        else
        {
          if(s2.top()<value) s2.push(value);
          else s2.push(s2.top());
        }
    }

    void pop() {
        s1.pop();
        s2.pop();
    }

    int top()
    {
      return s1.top();
    }

    int max() const {
        if(s2.empty()) return 0;
        return s2.top();
    }

    bool empty()
    {
      return s1.empty();
    }
};

class QueueWithMax {
  StackWithMax s1, s2;
  public:
    void push(int value)
    {
      s1.push(value);
    }

    int front()
    {
      {
        if(s2.empty())
        {
          while(!s1.empty())
          {
            s2.push(s1.top());
            s1.pop();
          }
        }
        return s2.top();
      }
    }
    void pop()
    {
      {
        if(s2.empty())
        {
          while(!s1.empty())
          {
            s2.push(s1.top());
            s1.pop();
          }
        }
        s2.pop();
      }
    }

    int max()
    {
      return s1.max()>s2.max()?s1.max():s2.max();
    }
};


void max_sliding_window_naive(vector<int> const & A, int w) {
    for (size_t i = 0; i < A.size() - w + 1; ++i) {
        int window_max = A.at(i);
        for (size_t j = i + 1; j < i + w; ++j)
            window_max = max(window_max, A.at(j));
        cout << window_max << " ";
    }

    return;
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int m = 0;
    cin >> m;
    QueueWithMax q;

    for (size_t i = 0; i < m; i++)
    {
      q.push(A[i]);
    }
    // cout<<q.s1.top()<<endl;


    for (size_t i = 0; i < n-m+1; i++) {
      // cout<<q.top()<<" ";
      cout<<q.max()<<" ";
      q.pop();
      q.push(A[i+m]);
    }




    // max_sliding_window_naive(A, m);

    return 0;
}
