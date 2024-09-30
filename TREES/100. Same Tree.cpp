/*
    Given roots of 2 binary trees, check if they're the same or not (same structure & values)
    Ex. p = [1,2,3] q = [1,2,3] -> true, p = [1,2] q = [1,null,2] -> false

    Check: (1) matching nulls, (2) non-matching nulls, (3) non-matching values

    Time: O(n)
    Space: O(n)
*/
// remember if the first if condition is checked compiler will not go for 2nd if condition
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
  bool isSameTree(TreeNode *p, TreeNode *q)
  {
    if (p == nullptr && q == nullptr)
    {
      return true;
    }
    if (p == nullptr || q == nullptr)
    {
      return false;
    }
    if (p->val != q->val)
    {
      return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};