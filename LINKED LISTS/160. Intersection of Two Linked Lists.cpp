// see neetcode video
// simple logic  come onn u can get itttt!
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    ListNode *trevA = headA;
    ListNode *trevB = headB;

    while (trevA != trevB)
    {
      if (trevA != nullptr)
      {
        trevA = trevA->next;
      }
      else
      {
        trevA = headB;
      }

      if (trevB != nullptr)
      {
        trevB = trevB->next;
      }
      else
      {
        trevB = headA;
      }
    }
    return trevA;
  }
};
