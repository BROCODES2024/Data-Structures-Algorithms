#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<vector<int>> subsets(vector<int> &nums)
  {
    int s = nums.size();
    int n = 1 << s;
    vector<vector<int>> ans;

    for (int num = 0; num < n; num++)
    {
      vector<int> subset;
      for (int i = 0; i < s; i++)
      {
        if (num & (1 << i))
        {
          subset.push_back(nums[i]);
        }
      }
      ans.push_back(subset);
    }

    return ans;
  }
};
