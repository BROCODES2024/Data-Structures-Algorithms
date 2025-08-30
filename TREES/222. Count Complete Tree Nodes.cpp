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
    int findLeftHeight(TreeNode *root)
    {
        int count = 0;
        while (root)
        {
            root = root->left;
            count++;
        }
        return count;
    }
    int findRightHeight(TreeNode *root)
    {
        int count = 0;
        while (root)
        {
            root = root->right;
            count++;
        }
        return count;
    }
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = findLeftHeight(root);
        int r = findRightHeight(root);
        if (l == r)
            return pow(2, l) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};