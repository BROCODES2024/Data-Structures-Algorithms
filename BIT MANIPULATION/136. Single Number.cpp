/*
    Given int array, every element appears twice except 1, find it
    Ex. nums = [2,2,1] -> 1, nums = [4,1,2,1,2] -> 4
    ex 1^1 = 0;0^0 = 0;1^0=1;
    ex 4^2 = 100^010 = 110
    a XOR a returns 0, so returns 0 for all except the unique one
    Time: O(n)
    Space: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    int result = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      result = result ^ nums[i];
    }

    return result;
  }
};
