/*
process: add two numbers use carry and sum variables use dummy node
also try add two numbers 2
*/
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
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr)
    {
      int summ = carry;
      if (l1 != nullptr)
      {
        summ += l1->val;
        l1 = l1->next;
      }
      if (l2 != nullptr)
      {
        summ += l2->val;
        l2 = l2->next;
      }
      ListNode *newnode = new ListNode(summ % 10);
      temp->next = newnode;
      temp = newnode;
      carry = summ / 10;
    }
    if (carry != 0)
    {
      ListNode *newnode = new ListNode(carry);
      temp->next = newnode;
    }
    return dummy->next;
  }
};