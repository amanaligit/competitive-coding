
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->val == INT_MAX)
            {
                return true;
            }
            ptr->val = INT_MAX;
            ptr = ptr->next;
        }
        return false;
    }
};