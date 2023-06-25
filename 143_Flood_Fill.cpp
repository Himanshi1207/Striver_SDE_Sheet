#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int color, int originalColor)
    {
        if (sr < 0 or sr >= image.size() or sc < 0 or sc >= image[0].size() or image[sr][sc] != originalColor or image[sr][sc] == color)
            return;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        image[sr][sc] = color;
        for (int i = 0; i < 4; i++)
        {
            int nsr = dr[i] + sr;
            int nsc = dc[i] + sc;
            dfs(image, nsr, nsc, color, originalColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int originalColor = image[sr][sc];
        dfs(image, sr, sc, color, originalColor);
        return image;
    }
};