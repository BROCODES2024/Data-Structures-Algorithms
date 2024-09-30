// O(N),O(N)
// process:
/*first we grate new nodes without linking them using hash map and then we link them with random and next*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> nodes;
        Node *h = head;

        while (h)
        {
            nodes[h] = new Node(h->val);
            h = h->next;
        }
        h = head;
        while (h)
        {
            Node *newNode = nodes[h];
            newNode->next = nodes[h->next];
            newNode->random = nodes[h->random];
            h = h->next;
        }
        return nodes[head];
    }
};