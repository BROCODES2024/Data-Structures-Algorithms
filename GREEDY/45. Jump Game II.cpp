/*
    Given int array, determine min jumps to reach last index
    Ex. nums = [2,3,1,1,4] -> 2, index 0 to 1 to last

    Greedy: At each point, determine furthest reachable, jump to it

    Time: O(n)
    Space: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, res = 0;
        while (r < nums.size() - 1) {
            int maxJump = 0;
            for (int i = l; i <= r; ++i) {
                maxJump = std::max(maxJump, i + nums[i]);
            }
            l = r + 1;
            r = maxJump;
            res++;
        }
        return res;
    }
};