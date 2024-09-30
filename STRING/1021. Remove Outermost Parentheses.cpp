#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  string removeOuterParentheses(string s)
  {
    int open = 0;
    int close = 0;
    string res = "";
    int start = 0;
    for (int i = 0; i < s.size(); i++)
    {
      char c = s[i];
      if (c == '(')
      {
        open++;
      }
      else
      {
        close++;
      }
      if (open == close)
      {
        res += s.substr(start + 1, i - start - 1);
        start = i + 1;
      }
    }
    return res;
  }
};