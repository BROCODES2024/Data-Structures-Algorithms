/*my approach :
first check numer if its a prime or not , then if prime save it in the array;
at last iterate through array using two pointers and save pairs if they are right!!
*/
/*
Time Complexity (TC):

The Sieve of Eratosthenes takes O(n log log n) time to find primes up to n.
Constructing the list of prime numbers takes O(n) time.
The two-pointer approach takes O(n) time to find pairs.
Overall, the time complexity is O(n log log n).
Space Complexity (SC):

The boolean vector isPrime requires O(n) space.
The vector primes requires O(n) space.
The space complexity is dominated by the boolean vector and is O(n).
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>

using namespace std;

class Solution
{
public:
  vector<vector<int>> findPrimePairs(int n)
  {
    vector<vector<int>> ans;
    if (n < 4)
    {
      return ans;
    }

    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= sqrt(n); ++i)
    {
      if (isPrime[i])
      {
        for (int j = i * i; j <= n; j += i)
        {
          isPrime[j] = false;
        }
      }
    }

    vector<int> primes;
    for (int i = 2; i <= n; ++i)
    {
      if (isPrime[i])
      {
        primes.push_back(i);
      }
    }

    int i = 0;
    int j = primes.size() - 1;
    while (i <= j)
    {
      if (primes[i] + primes[j] == n)
      {
        ans.push_back({primes[i], primes[j]});
        ++i;
        --j;
      }
      else if (primes[i] + primes[j] < n)
      {
        ++i;
      }
      else
      {
        --j;
      }
    }

    return ans;
  }
};
