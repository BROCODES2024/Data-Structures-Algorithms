#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int sumOfEncryptedInt(vector<int> &nums)
  {
    int ans = 0;
    int lar = 0, newnum = 0, count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] / 10 == 0)
      {
        ans += nums[i];
      }
      else
      {
        lar = 0, count = 0;
        int num = nums[i];
        while (num)
        {
          lar = max(lar, (num % 10));
          count++;
          num /= 10;
        }
        newnum = 0;
        while (count--)
        {
          newnum = (newnum * 10) + lar;
        }
        ans += newnum;
      }
    }
    return ans;
  }
};