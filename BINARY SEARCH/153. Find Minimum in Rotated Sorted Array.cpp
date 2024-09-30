// Neetcode solution Ologn time O1 space binary search
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int findMin(vector<int> &nums)
  {
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    int mini = INT_MAX;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (nums[low] <= nums[high])
      {
        mini = min(mini, nums[low]);
        break;
      }
      else if (nums[low] <= nums[mid])
      {
        mini = min(mini, nums[low]);
        low = mid + 1;
      }
      else
      {
        mini = min(nums[mid], mini);
        high = mid - 1;
      }
    }
    return mini;
  }
};