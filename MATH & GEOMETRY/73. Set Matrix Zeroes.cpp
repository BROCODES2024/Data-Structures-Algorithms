/*
    Given matrix, if element 0, set entire row/col to 0

    Use 1st row/col as flag to determine if entire row/col 0

    Time: O(mn)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int rowsize = matrix.size();
    int colsize = matrix[0].size();
    int rowzero = false;
    for (int row = 0; row < rowsize; row++)
    {
      for (int col = 0; col < colsize; col++)
      {
        if (matrix[row][col] == 0)
        {
          matrix[0][col] = 0;
          if (row > 0)
          {
            matrix[row][0] = 0;
          }
          else
          {
            rowzero = true;
          }
        }
      }
    }
    for (int row = 1; row < rowsize; row++)
    {
      for (int col = 1; col < colsize; col++)
      {
        if (matrix[0][col] == 0 || matrix[row][0] == 0)
        {
          matrix[row][col] = 0;
        }
      }
    }
    if (matrix[0][0] == 0)
    {
      for (int row = 0; row < rowsize; row++)
      {
        matrix[row][0] = 0;
      }
    }
    if (rowzero)
    {
      for (int col = 0; col < colsize; col++)
      {
        matrix[0][col] = 0;
      }
    }
  }
};