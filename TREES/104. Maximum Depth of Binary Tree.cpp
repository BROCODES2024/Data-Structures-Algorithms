
/*
    Given root of binary tree, return max depth (# nodes along longest path from root to leaf)

    At every node, max depth is the max depth between its left & right children + 1
    using recursion

    Time: O(n)
    Space: O(n)
*/
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
  int maxDepth(TreeNode *root)
  {
    if (root == nullptr)
    {
      return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};
