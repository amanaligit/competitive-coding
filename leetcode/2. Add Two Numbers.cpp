
//   Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2 && !carry)
    {
        ListNode *ans = new ListNode((l1->val + l2->val) % 10);
        ListNode *curr = ans;
        bool carry = (l1->val + l2->val) / 10;
        l1 = l1->next;
        l2 = l2->next;
        while (l1 != nullptr || l2 != nullptr)
        {
            int val1 = l1 == nullptr ? 0 : l1->val;
            int val2 = l2 == nullptr ? 0 : l2->val;
            curr->next = new ListNode((val1 + val2 + (int)carry) % 10);
            curr = curr->next;
            carry = (val1 + val2 + (int)carry) / 10;
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }
        return ans;
    }
};