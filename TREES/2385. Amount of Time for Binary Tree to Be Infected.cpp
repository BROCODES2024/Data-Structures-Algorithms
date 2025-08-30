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
    void mapParentNodes(unordered_map<TreeNode *, TreeNode *> &parentMap,
                        TreeNode *root, TreeNode *&targetNode, int target)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->val == target)
            {
                targetNode = node; // Find the target node
            }

            if (node->left)
            {
                parentMap[node->left] = node;
                q.push(node->left);
            }

            if (node->right)
            {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
    }

    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<TreeNode *, TreeNode *> parentMap;
        TreeNode *targetNode = nullptr;

        // Step 1: Map each node to its parent and find the target node
        mapParentNodes(parentMap, root, targetNode, start);

        // Step 2: Perform BFS from the target node to simulate the burning process
        unordered_set<TreeNode *> visited;
        queue<TreeNode *> q;
        q.push(targetNode);
        visited.insert(targetNode);

        int time = 0;

        while (!q.empty())
        {
            int size = q.size();
            bool burned = false;

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                // Check left child
                if (node->left && visited.find(node->left) == visited.end())
                {
                    q.push(node->left);
                    visited.insert(node->left);
                    burned = true;
                }

                // Check right child
                if (node->right && visited.find(node->right) == visited.end())
                {
                    q.push(node->right);
                    visited.insert(node->right);
                    burned = true;
                }

                // Check parent
                if (parentMap.find(node) != parentMap.end() &&
                    visited.find(parentMap[node]) == visited.end())
                {
                    q.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                    burned = true;
                }
            }

            if (burned)
            {
                time++;
            }
        }

        return time;
    }
};