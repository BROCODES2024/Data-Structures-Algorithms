#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;     // Last element in nums1's initial part
        int j = m + n - 1; // Last position in nums1
        int k = n - 1;     // Last element in nums2

        while (k >= 0)
        { // Continue until all elements from nums2 are merged
            if (i >= 0 && nums1[i] > nums2[k])
            { // Check i >= 0 to prevent invalid access
                nums1[j] = nums1[i];
                i--;
                j--;
            }
            else
            {
                nums1[j] = nums2[k];
                k--;
                j--;
            }
        }
    }
};
