#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <stack>
using namespace std;

using std::cin;
using std::string;
using std::vector;
using std::cout;
using std::max_element;

class StackWithMax {
    stack <int> s1, s2;

  public:

    void Push(int value) {
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

    void Pop() {
        s1.pop();
        s2.pop();

    }

    int Max() const {
        return s2.top();
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    string query;
    string value;

    StackWithMax stack;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == "push") {
            cin >> value;
            stack.Push(std::stoi(value));
        }
        else if (query == "pop") {
            stack.Pop();
        }
        else if (query == "max") {
            cout << stack.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}
