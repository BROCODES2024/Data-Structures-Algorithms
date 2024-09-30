/* process:
We are going to use two pointers (technically, three pointers). approach, but a bit different,
We will start from the last element of both arrays if the element of the second array
is greater than the 1st element, replace the last element of the first row, and continue by doing k-- j--, and if the 
If the last element of the second array is less than the first, then nums1[k]=nums1[i] and then k--,i--
*/
// tc : O(N)
// sc : O(1)
/*
for test case 2;
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
i = 0, j = -1, k = 0: The loop condition is false because j is not greater than or equal to 0. The loop exits.
The merged nums1 array after this process is still [1], which is the expected output.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (j >= 0)
    {
      if (i >= 0 && nums1[i] > nums2[j])
      {
        nums1[k] = nums1[i];
        k--;
        i--;
      }
      else
      {
        nums1[k] = nums2[j];
        k--;
        j--;
      }
    }
  }
};