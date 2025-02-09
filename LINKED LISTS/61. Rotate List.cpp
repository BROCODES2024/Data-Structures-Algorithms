struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  ListNode *rotateRight(ListNode *head, int k)
  {
    if (head == NULL || head->next == NULL || k == 0)
    {
      return head;
    }

    ListNode *curr = head;
    int len = 1;

    while (curr->next != NULL)
    {
      curr = curr->next;
      len++;
    }
    curr->next = head;
    k = k % len;
    k = len - k;

    while (k--)
    {
      curr = curr->next;
    }
    head = curr->next;
    curr->next = NULL;
    return head;
  }
};