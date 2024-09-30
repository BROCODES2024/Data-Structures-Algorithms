// This approach counts the frequency of characters in one string and then adjusts the count by decrementing for the other string.
// If the strings are anagrams, the frequency of each character will cancel out, resulting in a map with all zero frequencies.
// tc and sc botn O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool isAnagram(string s, string t)
  {
    unordered_map<char, int> count;
    for (auto x : s)
    {
      count[x]++;
    }
    for (auto x : t)
    {
      count[x]--;
    }
    for (auto x : count)
    {
      if (x.second != 0)
      {
        return false;
      }
    }
    return true;
  }
};