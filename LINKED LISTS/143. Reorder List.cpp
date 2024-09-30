/*
process: first use fast and slow method to find the middle node(dont forget to use prev make sure at last prev->next would be null)
then reverse the second half
and finally merge both
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
  void reorderList(ListNode *head)
  {
    if (head->next == nullptr)
    {
      return;
    }
    ListNode *prev = nullptr;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev->next = nullptr;
    ListNode *l1 = head;
    ListNode *l2 = reverse(slow);
    merge(l1, l2);
  }
  ListNode *reverse(ListNode *head)
  {
    ListNode *prev = nullptr;
    ListNode *temp = head;
    while (temp != nullptr)
    {
      ListNode *nxt = temp->next;
      temp->next = prev;
      prev = temp;
      temp = nxt;
    }
    return prev;
  }
  void merge(ListNode *l1, ListNode *l2)
  {
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;
    while (l1 != nullptr && l2 != nullptr)
    {
      temp->next = l1;
      temp = l1;
      l1 = l1->next;
      temp->next = l2;
      temp = l2;
      l2 = l2->next;
    }
    if (l1)
    {
      temp->next = l1;
    }
    else
    {
      temp->next = l2;
    }
  }
};