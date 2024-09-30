// idea is to map each distinct number to its latest index and check/update for the difference betwen indices each time a number is seen again.
// Time and Space Complexity => O(n), where n is the size of nums
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(nums[i]) != mp.end() && i - mp[nums[i]] <= k)
            {
                return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};
