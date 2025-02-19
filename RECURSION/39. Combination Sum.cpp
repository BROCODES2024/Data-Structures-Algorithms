/*
    Given distinct int array & a target, return list of all unique combos that
   sum to target Ex. candidates = [2,3,6,7] target = 7 -> [[2,2,3],[7]]

    Backtracking, generate all combo sums, push/pop + index checking to explore
   new combos

    Time: O(2^target)
    Space: O(target)
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> res;
        helper(candidates, target, 0, curr, res);
        return res;
    }

private:
    void helper(vector<int>& cands, int target, int i, vector<int>& curr,
                vector<vector<int>>& res) {
        if (i >= cands.size() || target < 0)
            return;

        if (target == 0) {
            res.push_back(curr);
            return;
        }

        curr.push_back(cands[i]);

        helper(cands, target - cands[i], i, curr, res);

        curr.pop_back();

        helper(cands, target, i + 1, curr, res);
    }
};
