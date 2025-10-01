#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {src, 0}});

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!pq.empty())
        {
            auto [stops, it] = pq.front();
            auto [node, cost] = it;
            pq.pop();

            if (stops > k)
                continue;

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;

                if (cost + edW < dist[adjNode])
                {
                    dist[adjNode] = cost + edW;
                    pq.push({stops + 1, {adjNode, cost + edW}});
                }
            }
        }

        if (dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};