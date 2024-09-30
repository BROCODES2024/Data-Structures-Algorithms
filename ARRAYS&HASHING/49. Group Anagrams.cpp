// The intuition is to group words that are anagrams of each other together.
//  Anagrams are words that have the same characters but in a different order.
// tc O(n*m*log(n)) sc O(n+m)
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (auto s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        vector<vector<string>> ana;
        for (auto p : mp)
        {
            ana.push_back(p.second);
        }
        return ana;
    }
};