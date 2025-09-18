#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(vector<int> &vis, vector<int> adj[], int st)
    {
        vis[st] = 1;
        for (auto it : adj[st])
        {
            if (!vis[it])
            {
                dfs(vis, adj, it);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] && i != j)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                ans++;
                dfs(vis, adj, i);
            }
        }
        return ans;
    }
};