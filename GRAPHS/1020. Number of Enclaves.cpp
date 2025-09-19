#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n, m;
    vector<vector<int>> vis;
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dc = {0, 1, 0, -1};

    void dfs(int r, int c, vector<vector<int>> &grid)
    {
        vis[r][c] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                !vis[nr][nc] && grid[nr][nc] == 1)
            {
                dfs(nr, nc, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        vis.assign(n, vector<int>(m, 0));

        // 1. Traverse boundary cells and run DFS on connected lands
        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 1 && !vis[i][0])
                dfs(i, 0, grid);
            if (grid[i][m - 1] == 1 && !vis[i][m - 1])
                dfs(i, m - 1, grid);
        }
        for (int j = 0; j < m; j++)
        {
            if (grid[0][j] == 1 && !vis[0][j])
                dfs(0, j, grid);
            if (grid[n - 1][j] == 1 && !vis[n - 1][j])
                dfs(n - 1, j, grid);
        }

        // 2. Count unvisited land cells (these are enclaves)
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                    cnt++;
            }
        }
        return cnt;
    }
};
