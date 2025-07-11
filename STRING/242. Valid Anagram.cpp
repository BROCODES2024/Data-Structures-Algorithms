#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        if (n != m)
        {
            return false;
        }
        map<char, int> mpp1;
        for (int i = 0; i < n; i++)
        {
            mpp1[s[i]]++;
            mpp1[t[i]]--;
        }
        return false;
    }
};