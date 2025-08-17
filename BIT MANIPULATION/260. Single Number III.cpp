#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> singleNumber(vector<int> &A)
    {
        int n = A.size();
        int mask = 1;
        int Xor = 0;
        for (int i = 0; i < n; i++)
        {
            Xor ^= A[i];
        }

        while ((Xor & mask) == 0)
        {
            mask <<= 1;
        }

        int j = 0, k = 0;

        for (int i = 0; i < n; i++)
        {
            if ((mask & A[i]) == 0)
                j ^= A[i];
            else
                k ^= A[i];
        }
        cout << mask;

        vector<int> ans;
        ans.push_back(j);
        ans.push_back(k);
        return ans;
    }
};