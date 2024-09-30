/*
    Given int array & target, return indices of 2 nums that add to target
    Ex. nums = [2,7,11,15] & target = 9 -> [0,1], 2 + 7 = 9

    At each num, calculate complement, if exists in hash map then return

    Time: O(n)
    Space: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            int more = target - num;
            if (mpp.find(more) != mpp.end())
            {
                return {i, mpp[more]};
            }
            mpp[num] = i;
        }
        return {-1, -1};
    }
};