#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<int> ans;
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        priority_queue<pair<int, int>> q;
        for (auto it : freq)
        {
            // cout<<it.first<<it.second<<endl;
            q.push({it.second, it.first});
        }
        while (k--)
        {
            auto cur = q.top();
            q.pop();
            ans.push_back(cur.second);
        }
        return ans;
    }
};