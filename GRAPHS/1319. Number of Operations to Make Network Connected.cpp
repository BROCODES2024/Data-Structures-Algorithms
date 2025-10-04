#include <bits/stdc++.h>
using namespace std;
class DSU
{
public:
    vector<int> size, par;
    DSU(int n)
    {
        size.resize(n + 1, 1);
        par.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            par[i] = i;
        }
    }
    int findUPar(int node)
    {
        if (node == par[node])
            return node;
        return par[node] = findUPar(par[node]);
    }
    void unionBySize(int u, int v)
    {
        int up_u = findUPar(u);
        int up_v = findUPar(v);

        if (up_u == up_v)
            return;
        if (size[up_v] > size[up_u])
        {
            par[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else
        {
            par[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;
        DSU ds(n);
        for (int i = 0; i < connections.size(); i++)
        {
            int n1 = connections[i][0];
            int n2 = connections[i][1];
            ds.unionBySize(n1, n2);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.findUPar(i) == i)
                cnt++;
        }
        return cnt - 1;
    }
};