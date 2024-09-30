/*
    Given int array, return true if can rearrange cards into groupSize consecutive
    Ex. hand = [1,2,3,6,2,3,4,7,8], groupSize = 3 -> true, [1,2,3],[2,3,4],[6,7,8]

    Loop thru ordered map, for a value, check groupSize consecutive & remove

    Time: O(n log n)
    Space: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool isPossibleDivide(vector<int> &nums, int k)
  {
    int n = nums.size();
    if (n % k != 0)
    {
      return false;
    }
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
      m[nums[i]]++;
    }
    while (!m.empty())
    {
      int curr = m.begin()->first;
      for (int i = 0; i < k; i++)
      {
        if (m[curr + i] == 0)
        {
          return false;
        }
        m[curr + i]--;
        if (m[curr + i] == 0)
        {
          m.erase(curr + i);
        }
      }
    }
    return true;
  }
};