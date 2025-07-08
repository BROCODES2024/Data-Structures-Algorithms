#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int rows = mat.size();
        int cols = mat[0].size();
        int low = 0, high = cols - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int maxRow = 0;
            for (int i = 0; i < rows; i++)
            {
                if (mat[i][mid] > mat[maxRow][mid])
                {
                    maxRow = i;
                }
            }

            int left = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
            int right = (mid + 1 < cols) ? mat[maxRow][mid + 1] : -1;

            if (mat[maxRow][mid] > left && mat[maxRow][mid] > right)
            {
                return {maxRow, mid};
            }
            else if (mat[maxRow][mid] < left)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};
