/*
Time Complexity: O(N+M), where N = given row number, M = given column number.
Reason: We are starting traversal from (0, M-1), and at most, we can end up being in the cell (M-1, 0). So, the total distance can be at most (N+M). So, the time complexity is O(N+M).

Space Complexity: O(1) as we are not using any extra space.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &mat, int target)
  {
    int n = mat.size();
    int m = mat[0].size();
    int row = 0;
    int col = m - 1;
    while (row < n && col >= 0)
    {
      if (mat[row][col] == target)
      {
        return true;
      }
      else if (mat[row][col] < target)
      {
        row++;
      }
      else
      {
        col--;
      }
    }
    return false;
  }
};