#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    int n = nums.size();
    int elem = nums[0];
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      if (cnt == 0)
      {
        elem = nums[i];
      }
      if (nums[i] == elem)
      {
        cnt++;
      }
      else
      {
        cnt--;
      }
    }
    return elem;
  }
};