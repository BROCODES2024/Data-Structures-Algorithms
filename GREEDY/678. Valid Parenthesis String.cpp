#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool checkValidString(string s)
  {
    int mx = 0, mn = 0;
    for (auto i : s)
    {
      if (i == '(')
        mx++, mn++;
      if (i == ')')
        mn--, mx--;
      if (i == '*')
        mx++, mn--;
      if (mx < 0)
        return false;
      mn = max(mn, 0);
    }
    return mn == 0;
  }
};