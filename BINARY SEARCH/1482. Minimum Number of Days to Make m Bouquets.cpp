#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possible(vector<int> &arr, int day, int m, int k) {
        int n = arr.size(); // size of the array
        int cnt = 0;
        int noOfB = 0;
        // count the number of bouquets:
        for (int i = 0; i < n; i++) {
            if (arr[i] <= day) {
                cnt++;
            } else {
                //adjacent condition it makes sures only adjacent flowers are used
                //if a flower is grown and the next one isnt and the no of flowers are insufficent to make a bouquet then we skip by making cnt 0
                noOfB += (cnt / k);
                cnt = 0;
            }
        }
        noOfB += (cnt / k);
        return noOfB >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;//1ll is used to promote to long long
        int n = bloomDay.size(); // size of the array
        if (val > n) return -1; // impossible case.
        // apply binary search:
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        while (low <= high) {
            int mid = (low + high) / 2;
            if (possible(bloomDay, mid, m, k)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
