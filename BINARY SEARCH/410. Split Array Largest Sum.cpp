#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool possible(vector<int> &arr, int k, int mid, int n)
    {
        int cnt = 1;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mid)
            {
                return false; // A single element exceeds 'mid', split is impossible
            }
            if (arr[i] + sum > mid)
            {
                cnt++;
                sum = arr[i];
            }
            else
            {
                sum += arr[i];
            }
        }
        return cnt <= k;
    }

    int splitArray(vector<int> &arr, int k)
    {
        int n = arr.size();
        int low = min(arr[0], arr[n - 1]);
        int high = accumulate(arr.begin(), arr.end(), 0);
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (possible(arr, k, mid, n) == true)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};