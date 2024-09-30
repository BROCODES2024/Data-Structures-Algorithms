/*
    Given unsorted array, return length of longest consecutive sequence
    Ex. nums = [100,4,200,1,3,2] -> 4, longest is [1,2,3,4]

    Store in hash set, only check for longer seq if it's the beginning

    Time: O(n)
    Space: O(n)
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        unordered_set<int> st;
        for(int i = 0;i<n;i++){
            st.insert(nums[i]);
        }
        int longest = 1;
        for(auto it: st){
            if(st.find(it-1)==st.end()){
                int cnt = 1;
                int x = it;
                while(st.find(x+1)!=st.end()){
                    cnt++;
                    x++;
                }
                longest = max(longest,cnt);
            }
        }
        return longest;
    }
};
