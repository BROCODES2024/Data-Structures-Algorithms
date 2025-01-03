#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftsum(n, 0);
        vector<int> rightsum(n, 0);
        for (int i = 0; i < n; i++) {
            if (i >= 1) {
                leftsum[i] = nums[i - 1] + leftsum[i - 1];
            } else {
                leftsum[i] = 0;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i <= n - 2) {
                rightsum[i] = rightsum[i + 1] + nums[i + 1];
            } else {
                rightsum[i] = 0;
            }
        }
        vector<int> ans(nums.size(),0);
        for(int i = 0;i<n;i++){
            ans[i] = abs(leftsum[i]-rightsum[i]);
        }
        return ans;
    }
};