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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        if (head == nullptr)
            return head;
        while (fast != nullptr)
        {
            // 2 3
            fast = fast->next; // 2 4
            if (fast == nullptr)
                return slow;
            else
                fast = fast->next; // 3 5
            slow = slow->next;
        }
        return slow;
    }
};