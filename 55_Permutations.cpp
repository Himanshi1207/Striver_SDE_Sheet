// TC-exponential
// SC-O(N)
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void solve(vector<int> &nums, vector<int> &visited, int n, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ds.push_back(nums[i]);
                visited[i] = 1;
                solve(nums, visited, n, ans, ds);
                visited[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        vector<int> visited(n, 0);
        solve(nums, visited, n, ans, ds);
        return ans;
    }
};