#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
class Solution
{
public:
    long long modPow(long long x, long long n)
    {
        long long result = 1;
        x = x % mod;

        while (n > 0)
        {
            if (n % 2 == 1)
                result = (result * x) % mod;

            x = (x * x) % mod;
            n /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n)
    {
        long long even = n / 2 + n % 2;
        long long odd = n / 2;

        long long result = (modPow(5, even) * modPow(4, odd)) % mod;
        return (int)result;
    }
};
