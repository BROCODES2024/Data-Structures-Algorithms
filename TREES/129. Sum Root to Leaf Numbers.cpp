struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumNumbers(TreeNode* root) { return sumNumbersHelper(root, 0); }

    int sumNumbersHelper(TreeNode* root, int num) {
        if (root->left == nullptr && root->right == nullptr) {
            return num * 10 + root->val;
        } else {
            int sum = 0;
            if (root->left) {
                sum += sumNumbersHelper(root->left, num * 10 + root->val);
            }
            if (root->right) {
                sum += sumNumbersHelper(root->right, num * 10 + root->val);
            }
            return sum;
        }
    }
};