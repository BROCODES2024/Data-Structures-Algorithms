#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis = image;
        int flow = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] = color;
        int delrow[] = {0, 0, -1, 1};
        int delcol[] = {-1, 1, 0, 0};
        while (!q.empty())
        {
            int numrow = q.front().first;
            int numcol = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int row = numrow + delrow[i];
                int col = numcol + delcol[i];
                if (row >= 0 && row < n && col >= 0 && col < m && vis[row][col] != color && image[row][col] == flow)
                {
                    q.push({row, col});
                    vis[row][col] = color;
                }
            }
        }
        return vis;
    }
};