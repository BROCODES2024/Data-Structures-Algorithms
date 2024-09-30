/*simple logic lwt distance between slow and fast pointers be x wkt fast ptr moves 2 steps and slow moves 1 step
so for every move x dec by 2 and and incresed by 1 so net is x-1 so x will for sure become 0*/
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution
{
public:
  bool hasCycle(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (fast == slow)
      {
        return true;
      }
    }
    return false;
  }
};