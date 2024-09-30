#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int minimumOperations(vector<int> &nums)
  {
    unordered_set<int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] != 0)
      {
        mpp.insert(nums[i]);
      }
    }
    return mpp.size();
  }
};