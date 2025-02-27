#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int start = 0, end = n - 1;
        int ans = 0;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (citations[mid] >= n - mid)
            {
                ans = max(ans, n - mid);
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};