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
        ListNode *cur = head;
        vector<int *> b;
        while (cur != NULL)
        {
            for (int i = 0; i < b.size(); i++)
            {
                if (b[i] == &cur->val)
                {
                    return 1;
                }
            }
            b.push_back(&cur->val);
            cur = cur->next;
        }
        return 0;
    }
};