#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }

        vector<int> indeg(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            for (auto &it : adj[i])
            {
                indeg[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indeg[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto &it : adj[node])
            {
                indeg[it]--;
                if (indeg[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        return topo.size() == numCourses;
    }
};
