struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int height(TreeNode *root)
  {
    if (root == NULL)
    {
      return 0;
    }
    return 1 + max(height(root->left), height(root->right));
  }

  bool isBalanced(TreeNode *root)
  {
    if (root == NULL)
    {
      return true; // An empty tree is considered balanced
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};