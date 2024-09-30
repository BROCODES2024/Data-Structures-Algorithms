/*            s = "010110"
Lets just count no. of 1's and 0's.
            cnt1 = 3 and cnt0 = 3
Since we need greatest odd number we obviously need one 1
at the last to make it odd and best chances to make it greatest
is by putting rest every 1's at the front.

            ans = "11" + "000" + "1"

            ans = "110001"

Will work for all cases, try it out:)*/

/*
Complexity
Time complexity:
O(n)

Space complexity:
O(n)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int cnt1 = 0;
        int cnt0 = 0;
        for (auto a : s)
        {
            if (a == '1')
            {
                cnt1++;
            }
            else
            {
                cnt0++;
            }
        }
        string ans = string(cnt1 - 1, '1') + string(cnt0, '0') + '1';
        return ans;
    }
};