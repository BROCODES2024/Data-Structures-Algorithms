#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int minlen = INT_MAX;
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum<target){
            return 0;
        }
        sum = 0;
        for(int r = 0;r<nums.size();r++){
            sum+=nums[r];
            if(sum>=target){
                minlen = min(minlen,r-l+1);
            }
            while(sum>target){
                sum-=nums[l];
                l++;
                if(sum>=target){
                    minlen = min(minlen,r-l+1);
                }
            }
        }        
        return minlen;
    }
};