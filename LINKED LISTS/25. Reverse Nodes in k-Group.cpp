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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k == 1)
            return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = dummy;
        ListNode *nex = dummy;
        ListNode *pre = dummy;
        int c = 0;

        while (cur->next)
        {
            cur = cur->next;
            c++;
        }
        while (c >= k)
        {
            cur = pre->next;
            nex = cur->next;
            for (int i = 1; i < k; i++)
            {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            c -= k;
        }
        return dummy->next;
    }
};