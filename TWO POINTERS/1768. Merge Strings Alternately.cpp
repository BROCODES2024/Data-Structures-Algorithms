/*

Intuition:
The function iterates through word1 and word2 alternately, creating a new string with characters merged in an alternating fashion. It handles cases where one word is longer than the other, appending any remaining characters.

Time Complexity (TC):
O(max(m, n)), where m and n are the lengths of word1 and word2 respectively.

Space Complexity (SC):
O(m + n), as the function creates a new string to store the merged result.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  string mergeAlternately(string word1, string word2)
  {
    string t = "";
    int m = word1.size();
    int n = word2.size();
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
      t += word1[i];
      i++;
      t += word2[j];
      j++;
    }
    if (i < m)
    {
      for (int a = i; i < m; i++)
      {
        t += word1[i];
      }
    }
    if (j < n)
    {
      for (int b = j; j < n; j++)
      {
        t += word2[j];
      }
    }
    return t;
  }
};