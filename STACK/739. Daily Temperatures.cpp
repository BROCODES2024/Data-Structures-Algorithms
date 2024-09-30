/*
    Given array of temps, return an array w/ # of days until warmer
    Ex. temperature = [73,74,75,71,69,72,76,73] -> [1,1,4,2,1,1,0,0]

    Monotonic decr stack, at each day, compare incr from prev days

    Time: O(n)
    Space: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  vector<int> dailyTemperatures(vector<int> &temperatures)
  {
    int n = temperatures.size();
    stack<pair<int, int>> stk;
    vector<int> result(n);

    for (int i = 0; i < n; i++)
    {
      int currDay = i;
      int currTemp = temperatures[i];

      while (!stk.empty() && stk.top().second < currTemp)
      {
        result[stk.top().first] = currDay - stk.top().first;
        stk.pop();
      }

      stk.push({currDay, currTemp});
    }

    return result;
  }
};