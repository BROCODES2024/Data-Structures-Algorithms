// using reverse linked list and the concept of adding two numbers
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
  ListNode *reverselist(ListNode *head)
  {
    ListNode *temp = head;
    ListNode *prev = nullptr;
    while (temp)
    {
      ListNode *nxt = temp->next;
      temp->next = prev;
      prev = temp;
      temp = nxt;
    }
    return prev;
  }

  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode *h1 = reverselist(l1);
    ListNode *h2 = reverselist(l2);
    ListNode *dummy = new ListNode(0);
    ListNode *temp = dummy;
    int carry = 0;
    while (h1 != nullptr || h2 != nullptr)
    {
      int summ = carry;
      if (h1 != nullptr)
      {
        summ += h1->val;
        h1 = h1->next;
      }
      if (h2 != nullptr)
      {
        summ += h2->val;
        h2 = h2->next;
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
    return reverselist(dummy->next); // Add this return statement
  }
};