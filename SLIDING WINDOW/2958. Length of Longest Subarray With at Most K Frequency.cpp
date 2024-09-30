/*
we are using sliding window process here , we will be using a map and store the frequency of the element
if the frequency of the element goes beyond the allowed max(k) we will decrese the frquency of the element at left pointer(if
its same as the element at right pointer else we use a while loop and decrese freq of every element till the same element is found)
**we keep moving the left pointer** and we use a variable to store the max size
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> mpp;
        int l = 0;
        for(int r=0;r<nums.size();r++){
            mpp[nums[r]]++;
            if(mpp[nums[r]]>k){
                while(nums[l]!=nums[r]){
                    mpp[nums[l]]--;
                    l++;
                }
                mpp[nums[l]]--;
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};