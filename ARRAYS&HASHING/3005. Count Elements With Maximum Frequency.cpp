#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int maxFrequencyElements(vector<int> &nums)
  {
    unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
      mpp[nums[i]]++;
    }
    int maxfreq = INT_MIN;
    for (auto it : mpp)
    {
      if (it.second > maxfreq)
      {
        maxfreq = max(maxfreq, it.second);
      }
    }
    int cnt = 0;
    for (auto it : mpp)
    {
      if (it.second == maxfreq)
      {
        cnt += it.second;
      }
    }
    return cnt;
  }
};