#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        bt(curr,ans,n,k,1);
        return ans;
    }
    void bt(vector<int> &curr,vector<vector<int>> &ans,int n, int k,int start){
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }
        for(int i = start;i<=n;i++){
            curr.push_back(i);
            bt(curr,ans,n,k,i+1);
            curr.pop_back();
        }
    }
};