
#include <unordered_map>
using namespace std;
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <stack>
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<int> postorder(Node *root)
    {
        vector<int> answer;
        stack<Node *> s1;
        stack<Node *> s2;
        if (root == nullptr)
            return answer;
        s1.push(root);
        while (!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();
            s2.push(temp);
            for (auto child : temp->children)
            {
                s1.push(child);
            }
        }
        while (!s2.empty())
        {
            answer.push_back(s2.top()->val);
            s2.pop();
        }
        return answer;
    }
};