// If we flatten the given 2D matrix to a 1D array, the 1D array will also be sorted.
//  By utilizing binary search on this sorted 1D array to locate the ‘target’ element, we can further decrease the time complexity.
/*
Time Complexity: O(log(NxM)), where N = given row number, M = given column number.
Reason: We are applying binary search on the imaginary 1D array of size NxM.
Space Complexity: O(1) as we are not using any extra space.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = n * m - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int row = mid / m;
            int col = mid % m;
            if (matrix[row][col] == target)
            {
                return true;
            }
            else if (target > matrix[row][col])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }
};