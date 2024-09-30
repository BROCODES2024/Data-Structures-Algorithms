#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  string reverseWords(string s)
  {
    int l = 0, n = s.size(), r = s.size() - 1;
    int ee = r;
    string ans = "";

    while (l <= r)
    {
      while (r >= 0 && s[r] == ' ')
        r--;
      if (r < 0)
        break;
      ee = r;

      while (r >= 0 && s[r] != ' ')
      {
        r--;
      }
      ans += s.substr(r + 1, ee - r);
      ans.push_back(' ');
    }
    ans.pop_back();
    return ans;
  }
};