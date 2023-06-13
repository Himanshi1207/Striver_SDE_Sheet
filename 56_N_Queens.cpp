// TC-exponential
// SC-O(N*N)
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossibleToPlace(int col, int row, vector<string> &ds, int n)
    {
        int nrow = row;
        int ncol = col;
        while (nrow >= 0 and ncol >= 0)
        {
            if (ds[nrow--][ncol--] == 'Q')
                return false;
        }
        nrow = row, ncol = col;
        while (ncol >= 0)
        {
            if (ds[nrow][ncol--] == 'Q')
                return false;
        }
        nrow = row, ncol = col;
        while (ncol >= 0 and nrow < n)
        {
            if (ds[nrow++][ncol--] == 'Q')
                return false;
        }
        return true;
    }
    void solve(int col, int n, vector<vector<string>> &ans, vector<string> &ds)
    {
        if (col == n)
        {
            ans.push_back(ds);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isPossibleToPlace(col, row, ds, n))
            {
                ds[row][col] = 'Q';
                solve(col + 1, n, ans, ds);
                ds[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        string s(n, '.');
        vector<string> ds(n);
        for (int i = 0; i < n; i++)
        {
            ds[i] = s;
        }
        solve(0, n, ans, ds);
        return ans;
    }
};