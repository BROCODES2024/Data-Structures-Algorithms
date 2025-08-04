#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void combi(vector<int> candidates, int target, vector<vector<int>> &ans, vector<int> temp, int ind)
    {
        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }
        for (int i = ind; i < candidates.size(); i++)
        {
            if (candidates[i] > target)
            {
                break;
            }
            if (i > ind && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            temp.push_back(candidates[i]);
            combi(candidates, target - candidates[i], ans, temp, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        combi(candidates, target, ans, temp, 0);
        return ans;
    }
};