// TC-Exponential as recursive
// SC-Auxilliary Stack space
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void helper(vector<int> &nums, int idx, vector<int> &ds, vector<vector<int>> &ans)
    {
        ans.push_back(ds);
        for (int i = idx; i < nums.size(); i++)
        {
            if (i != idx and nums[i] == nums[i - 1])
                continue;
            ds.push_back(nums[i]);
            helper(nums, i + 1, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        helper(nums, 0, ds, ans);
        return ans;
    }
};