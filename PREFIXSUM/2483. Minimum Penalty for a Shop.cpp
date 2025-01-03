#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bestClosingTime(string cust) {
        int n = cust.size();
        vector<int> pre(n+1, 0);   
        vector<int> post(n+1, 0);  
        for(int i = 1; i <= n; i++) {
            if(cust[i-1] == 'N') {
                pre[i] = pre[i-1] + 1;
            } else {
                pre[i] = pre[i-1];
            }
        }
        for(int i = n-1; i >= 0; i--) {
            if(cust[i] == 'Y') {
                post[i] = post[i+1] + 1;
            } else {
                post[i] = post[i+1];
            }
        }
        int mini = INT_MAX;
        int bestTime = 0;
        for(int i = 0; i <= n; i++) {
            int totalCost = pre[i] + post[i];
            if (totalCost < mini) {
                mini = totalCost;
                bestTime = i;
            }
        }
        return bestTime;
    }
};
