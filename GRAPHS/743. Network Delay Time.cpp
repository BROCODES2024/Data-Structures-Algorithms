#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {

        vector<vector<pair<int, int>>> adj(n + 1);

        for (int i = 0; i < times.size(); i++)
        {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v, w});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while (!pq.empty())
        {
            int nodeDist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int neigh = it.first;
                int weight = it.second;

                if (dist[neigh] > nodeDist + weight)
                {
                    dist[neigh] = nodeDist + weight;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i < n + 1; i++)
        {
            ans = max(ans, dist[i]);
        }

        if (ans == INT_MAX)
            return -1;

        return ans;
    }
};