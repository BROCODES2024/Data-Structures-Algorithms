#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int noofdays(vector<int> &weights, int maxweight){
        int totaldays = 0;
        int n = weights.size();
        int currsum = 0;
        for(int i = 0;i<n;i++){
            if(currsum+weights[i]<=maxweight){
                currsum+=weights[i];
            }else{
                totaldays++;
                currsum = weights[i];
            }
        }
        totaldays++;
        return totaldays;
        
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid = (low+high)/2;
            if(noofdays(weights,mid)<=days){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};