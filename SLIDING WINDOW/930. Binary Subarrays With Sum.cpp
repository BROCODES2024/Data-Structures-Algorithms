#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int numSubarraysWithSum(vector<int> &nums, int goal)
  {
    return helper(nums, goal) - helper(nums, goal - 1);
  }

  int helper(vector<int> &nums, int goal)
  {
    if (goal < 0)
      return 0;

    int sum = 0;
    int rc = 0;
    int j = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      int n = nums[i];
      sum += n;

      while (sum > goal)
      {
        sum -= nums[j];
        j++;
      }

      rc += (i - j + 1);
    }

    return rc;
  }
};
