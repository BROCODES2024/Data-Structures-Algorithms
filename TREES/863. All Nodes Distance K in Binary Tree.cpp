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
    void parent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &mpp)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->left)
            {
                mpp[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                mpp[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> mpp;
        parent(root, mpp);
        queue<TreeNode *> q;
        q.push(target);
        unordered_map<TreeNode *, bool> vis;
        vis[target] = true;
        int currlev = 0;
        while (!q.empty())
        {
            int size = q.size();
            if (currlev == k)
            {
                break;
            }
            currlev++;
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left && !vis[curr->left])
                {
                    q.push(curr->left);
                    vis[curr->left] = true;
                }
                if (curr->right && !vis[curr->right])
                {
                    q.push(curr->right);
                    vis[curr->right] = true;
                }
                if (mpp[curr] && !vis[mpp[curr]])
                {
                    q.push(mpp[curr]);
                    vis[mpp[curr]] = true;
                }
            }
        }
        vector<int> res;
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            res.push_back(curr->val);
        }
        return res;
    }
};