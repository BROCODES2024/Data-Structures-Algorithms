#include <bits/stdc++.h>
using namespace std;
class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        prefix = vector<int>(nums.size(),0);
        prefix[0] = nums[0];
        for(int i = 1;i<nums.size();i++){
            prefix[i] = prefix[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left>=1){
        return prefix[right] - prefix[left-1];
        }else{
            return prefix[right];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */