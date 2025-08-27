#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    void traverse(TreeNode *root, int x, int y, map<int, multiset<pair<int, int>>> &mp)
    {
        if (root == nullptr)
        {
            return;
        }
        mp[x].insert({y, root->val});
        traverse(root->left, x - 1, y + 1, mp);
        traverse(root->right, x + 1, y + 1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, multiset<pair<int, int>>> mp;
        traverse(root, 0, 0, mp);
        vector<vector<int>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            vector<int> verti;
            for (auto jt = it->second.begin(); jt != it->second.end(); ++jt)
            {
                verti.push_back(jt->second);
            }
            ans.push_back(verti);
        }
        return ans;
    }
};