#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int memo[101][501];
    int solve(int arr[], int i, int j)
    {
        // base case
        if (i >= j)
            return 0;
        if (memo[i][j] != -1)
            return memo[i][j]; // if already filled
        int mn = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int temp_ans = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
            if (temp_ans < mn)
            {
                mn = temp_ans;
            }
        }
        return memo[i][j] = mn;
    }

    int matrixMultiplication(int N, int arr[])
    {
        // Write your code here
        memset(memo, -1, sizeof(memo));
        int ans = solve(arr, 1, N - 1);
        return ans;
    }
};