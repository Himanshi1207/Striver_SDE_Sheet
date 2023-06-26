#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int x, int y, vector<vector<char>> &grid)
    {
        grid[x][y] = '0';
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dr[i];
            int ny = y + dc[i];
            if (nx >= 0 and nx < grid.size() and ny >= 0 and ny < grid[0].size() and grid[nx][ny] == '1')
            {
                dfs(nx, ny, grid);
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};