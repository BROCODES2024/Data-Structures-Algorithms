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
    int getMaxAns(TreeNode* curr, int& max_ans) {
        if (curr==NULL) return 0;
        int leftAns = max(0, getMaxAns(curr->left, max_ans));
        int rightAns = max(0, getMaxAns(curr->right, max_ans));
        max_ans = max(max_ans, curr->val + leftAns + rightAns);
        return max(leftAns, rightAns) + curr->val;
    }

    int maxPathSum(TreeNode* root) {
        int max_ans = INT_MIN;
        getMaxAns(root, max_ans);
        return max_ans;
    }
};