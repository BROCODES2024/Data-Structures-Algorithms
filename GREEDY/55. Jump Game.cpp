/*
    Given int array, return true if can reach last index
    Ex. nums = [2,3,1,1,4] -> true, index 0 to 1 to last

    Greedy: At each point, determine furthest reachable index

    Time: O(n)
    Space: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool canJump(vector<int> &nums)
  {
    int n = nums.size();
    int goal = n - 1;
    for (int i = n - 1; i >= 0; i--)
    {
      if (i + nums[i] >= goal)
      {
        goal = i;
      }
    }
    return (goal == 0);
  }
};