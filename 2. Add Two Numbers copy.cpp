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
        ListNode *l3;
        l3 = nullptr;
        ListNode *sta = l3;
        ListNode *cur = sta;
        while (l1 != nullptr || l2 != nullptr)
        {
            ListNode *node = new ListNode;
            node->next = nullptr;
            node->val = 0;
            if (sta == nullptr)
            {
                sta = node;
                cur = sta;
            }
            else if (cur == nullptr)
            { // cout<<"1";
                // 問題在這 cur指向cur->next的地址,但是cur->next搬家了，cur仍然指向舊的地址
                cur = node;
            }

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

            if (cur->val >= 10)
            {
                ListNode *node1 = new ListNode;
                node1->next = nullptr;
                node1->val = cur->val / 10;
                cur->val = cur->val % 10;
                cur->next = node1;
            }
            cout << cur->val << " ";
            cur = cur->next;
        }
        return sta;
    }
};
