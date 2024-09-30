#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int minimumBoxes(vector<int> &apple, vector<int> &capacity)
  {
    int i = 0;
    sort(capacity.begin(), capacity.end());
    int j = capacity.size() - 1;
    int apsum = 0;
    for (int i = 0; i < apple.size(); i++)
    {
      apsum += apple[i];
    }
    int cnt = 0;
    while (apsum > 0 && j >= 0)
    {
      apsum -= capacity[j];
      cnt++;
      if (apsum < 0)
      {
        apsum = 0;
      }
      j--;
    }
    return cnt;
  }
};