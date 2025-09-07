#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int curr = root->val;

        // If both p and q are greater than the current node, go to the right subtree
        if (curr < p->val && curr < q->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }

        // If both p and q are less than the current node, go to the left subtree
        if (curr > p->val && curr > q->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }

        // If neither of the above cases is true, this is the lowest common ancestor
        return root;
    }
};