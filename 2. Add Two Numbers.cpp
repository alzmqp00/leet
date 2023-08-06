#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *l3 = new ListNode;
        ListNode *sta = l3;
        ListNode *cur = sta;
        while (l1 != nullptr || l2 != nullptr)
        {

            if (l1 != nullptr)
            {
                cur->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                cur->val += l2->val;
                l2 = l2->next;
            }
            ListNode *node = new ListNode;
            node->next = nullptr;

            if (cur->val >= 10)
            {
                node->val = cur->val / 10;
                cur->val = cur->val % 10;
                cur->next = node;
            }
            else if (l1 == nullptr && l2 == nullptr)
                break;
            else
            {
                node->val = 0;
                cur->next = node;
            }

            cout << cur->val << " ";
            cur = cur->next;
        }
        return sta;
    }
};
