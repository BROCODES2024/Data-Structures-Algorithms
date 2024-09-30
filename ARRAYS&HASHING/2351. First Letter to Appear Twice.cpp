#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  char repeatedCharacter(string str)
  {
    unordered_map<char, int> mp;
    for (char &ch : str)
    {
      mp[ch]++;
      if (mp[ch] > 1)
      {
        return ch;
      }
    }
    char chr;
    return chr;
  }
};