#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool dfs(vector<int> &col, int currcol, const vector<vector<int>> &graph, int st)
    {
        col[st] = currcol;
        for (auto it : graph[st])
        {
            if (col[it] == -1)
            {
                if (!dfs(col, !currcol, graph, it))
                {
                    return false;
                }
            }
            else if (col[it] == currcol)
            {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> col(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (col[i] == -1)
            {
                if (!dfs(col, 0, graph, i))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
