#include <bits/stdc++.h>
using namespace std;
// User function template for C++

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        // Code here
        int n = matrix.size();
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == k or j == k or matrix[i][k] == -1 or matrix[k][j] == -1)
                        continue;
                    else if (matrix[i][j] == -1)
                    {
                        matrix[i][j] = INT_MAX;
                    }
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }
};