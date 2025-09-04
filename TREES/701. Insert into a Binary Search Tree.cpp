#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        TreeNode *nn = new TreeNode(val);
        if (root == NULL)
        {
            return nn;
        }
        TreeNode *curr = root;
        while (curr != NULL)
        {
            if (curr->val <= val)
            {
                if (curr->right != NULL)
                {
                    curr = curr->right;
                }
                else
                {
                    curr->right = nn;
                    break;
                }
            }
            else
            {
                if (curr->left != NULL)
                {
                    curr = curr->left;
                }
                else
                {
                    curr->left = nn;
                    break;
                }
            }
        }
        return root;
    }
};
