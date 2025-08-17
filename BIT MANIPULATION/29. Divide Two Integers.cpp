#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == divisor)
            return 1;

        bool sign = !((dividend < 0) ^ (divisor < 0)); // true if same sign

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);
        long long ans = 0;

        while (n >= d)
        {
            long long cnt = 0;
            while (n >= (d << (cnt + 1)))
            {
                cnt++;
            }
            ans += (1LL << cnt);
            n -= (d << cnt);
        }

        if (ans > INT_MAX)
        {
            return sign ? INT_MAX : INT_MIN;
        }

        return sign ? (int)ans : -(int)ans;
    }
};
