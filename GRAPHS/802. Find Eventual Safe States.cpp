#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        queue<int> q;
        int n = graph.size();
        vector<int> revadj[n];
        vector<int> outdeg(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (auto it : graph[i])
            {
                revadj[it].push_back(i);
                outdeg[i]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (outdeg[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            int num = q.front();
            q.pop();
            ans.push_back(num);
            for (auto it : revadj[num])
            {
                outdeg[it]--;
                if (outdeg[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};