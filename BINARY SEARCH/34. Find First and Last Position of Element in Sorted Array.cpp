#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int t)
  {
    int n = nums.size();
    int lb = lower_bound(nums.begin(), nums.end(), t) - nums.begin();
    if (lb == n || nums[lb] != t)
    {
      return {-1, -1};
    }
    int ub = upper_bound(nums.begin(), nums.end(), t) - nums.begin() - 1;
    return {lb, ub};
  }
};