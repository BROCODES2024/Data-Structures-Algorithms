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
class Solution {
public:
    void rec(TreeNode* root,vector<string> &ans,string curr){
        if(root==NULL){
            return;
        }
        if(root->left||root->right){
            curr+=(to_string(root->val)+"->");
        }
        else{
            curr+=(to_string(root->val));
            ans.push_back(curr);
        }
        rec(root->left,ans,curr);
        rec(root->right,ans,curr);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string curr = "";
        rec(root,ans,curr);
        return ans;
    }
};