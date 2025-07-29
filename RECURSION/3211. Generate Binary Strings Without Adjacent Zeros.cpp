#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rec(string curr, int n, vector<string> &res)
    {
        if (curr.length() == n)
        {
            res.push_back(curr);
            return;
        }
        if (curr.back() == '0')
        {
            rec(curr + '1', n, res);
        }
        else
        {
            rec(curr + '0', n, res);
            rec(curr + '1', n, res);
        }
    }
    vector<string> validStrings(int n)
    {
        vector<string> res;
        if (n == 1)
        {
            return {"0", "1"};
        }
        rec("0", n, res);
        rec("1", n, res);
        return res;
    }
};