#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rec(vector<vector<int>> &ans, int idx, vector<int> temp, vector<int> &nums)
    {
        if (idx >= nums.size())
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        rec(ans, idx + 1, temp, nums); // Include current element
        temp.pop_back();
        rec(ans, idx + 1, temp, nums); // Exclude current element
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        rec(ans, 0, temp, nums);
        return ans;
    }
};
