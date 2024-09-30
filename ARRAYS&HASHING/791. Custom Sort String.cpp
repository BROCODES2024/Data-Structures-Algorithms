#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  string customSortString(string order, string s)
  {
    string t = "";
    unordered_map<char, int> mpp;
    for (int i = 0; i < s.size(); i++)
    {
      mpp[s[i]]++;
    }
    for (int i = 0; i < order.size(); i++)
    {
      if (mpp.find(order[i]) != mpp.end())
      {
        t.append(mpp[order[i]], order[i]);
        mpp.erase(order[i]);
      }
    }
    for (auto it : mpp)
    {
      t.append(it.second, it.first);
    }
    return t;
  }
};