// TC-Exponential as recursive
// SC-Auxilliary Stack space
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void targetsum(vector<int> &candidates, int idx, vector<int> &v, vector<vector<int>> &ans, int target)
    {
        if (idx == candidates.size())
        {
            if (target == 0)
                ans.push_back(v);
            return;
        }
        if (candidates[idx] <= target)
        {
            v.push_back(candidates[idx]);
            targetsum(candidates, idx, v, ans, target - candidates[idx]);
            v.pop_back();
        }
        targetsum(candidates, idx + 1, v, ans, target);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> v;
        targetsum(candidates, 0, v, ans, target);
        return ans;
    }
};