#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxK(std::vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] > 0 && std::binary_search(nums.begin(), nums.end(), -nums[i])) {
                return nums[i];
            }
        }
        return -1;
    }
};