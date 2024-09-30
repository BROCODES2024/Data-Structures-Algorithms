/*
    Given array prices, return max profit w/ 1 buy & 1 sell
    Ex. prices = [7,1,5,3,6,4] -> 5 (buy at $1, sell at $6)

    For each, get diff b/w that & min value before, store max

    Time: O(n)
    Space: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int buy = INT_MAX;
    int profit = 0;
    int n = prices.size();
    for (int i = 0; i < n; i++)
    {
      profit = max(prices[i] - buy, profit);
      buy = min(buy, prices[i]);
    }
    return profit;
  }
};
