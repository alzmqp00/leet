#include <iostream>
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }

        ListNode *cur1;
        cur1 = list1;
        int num;
        ListNode *cur2;
        while (cur1 != nullptr)
        {

            num = cur1->val;
            cur2 = list2;
            while (cur2 != nullptr)
            {
                // 百開頭
                // 1 2 4
                // 1 3 4
                if (cur2->val > num)
                {
                    ListNode *temp1;
                    temp1 = new ListNode;
                    temp1->next = list2;
                    temp1->val = num;
                    list2 = temp1;
                    break;
                }
                else if (num >= cur2->val && (cur2->next == nullptr || num < cur2->next->val))
                {
                    ListNode *temp1;
                    temp1 = new ListNode;
                    temp1->next = cur2->next;
                    temp1->val = num;
                    cur2->next = temp1;
                    break;
                }
                cur2 = cur2->next;
            }
            cur1 = cur1->next;
        }
        cur2 = list2;
        while (cur2 != nullptr)
        {
            cout << cur2->val << " ";
            cur2 = cur2->next;
        }
        return list2;
    }
};
int main()
{
    return 0;
}