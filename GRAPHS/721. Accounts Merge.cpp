#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, rank;

public:
    DisjointSet(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    int findPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if (rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        unordered_map<string, int> um;
        int n = accounts.size();
        DisjointSet ds(n);
        for (int i = 0; i < n; i++)
        {
            int m = accounts[i].size();
            for (int j = 1; j < m; j++)
            {
                string ref = accounts[i][j];
                if (um.find(ref) != um.end())
                {
                    ds.unionByRank(i, um[ref]);
                }
                else
                    um[ref] = i;
            }
        }
        vector<vector<string>> vs(n);
        for (auto it : um)
        {
            int parent = ds.findPar(it.second);
            vs[parent].push_back(it.first);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (vs[i].size() > 0)
            {
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                sort(vs[i].begin(), vs[i].end());
                for (auto x : vs[i])
                    temp.push_back(x);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};