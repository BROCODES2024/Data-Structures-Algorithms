#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxcount = 0;
        int sum = 0;
        int i = 0;
        int j = 0;
        unordered_map<int, int> mpp;
        while (j < fruits.size()) {
            mpp[fruits[j]]++;
            sum++;
            while (mpp.size() > 2) {
                mpp[fruits[i]]--;
                sum--;
                if (mpp[fruits[i]] == 0) {
                    mpp.erase(fruits[i]);
                }
                i++;
            }
            maxcount = max(maxcount, sum);
            j++;
        }
        return maxcount;
    }
};