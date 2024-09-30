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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        queue<pair<TreeNode *, bool>> q;
        q.push({root, false});
        int totalsum = 0;
        while (!q.empty())
        {
            pair<TreeNode *, bool> frontPair = q.front();
            TreeNode *node = frontPair.first;
            bool isLeft = frontPair.second;

            q.pop();
            if (isLeft && !node->left && !node->right)
            {
                totalsum += node->val;
            }
            if (node->left)
            {
                q.push({node->left, true});
            }
            if (node->right)
            {
                q.push({node->right, false});
            }
        }
        return totalsum;
    }
};