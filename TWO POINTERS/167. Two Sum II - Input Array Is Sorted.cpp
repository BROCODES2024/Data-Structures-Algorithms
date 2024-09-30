// solution is to use a two-pointer approach to find a pair of numbers in the sorted array that sums up to the target value.
//  Complexity
//  Time complexity: O(n), where n is the length of the input array. The two-pointer approach iterates through the array once.
//  Space complexity: O(1), as the algorithm uses constant space.
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int i = 0;
        int j = numbers.size() - 1;

        vector<int> result;

        while (i < j)
        {
            int sum = numbers[i] + numbers[j];
            if (sum < target)
            {
                i++;
            }
            else if (sum > target)
            {
                j--;
            }
            else
            {
                result.push_back(i + 1);
                result.push_back(j + 1);
                break;
            }
        }

        return result;
    }
};