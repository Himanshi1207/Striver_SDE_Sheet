#include <bits/stdc++.h>
using namespace std;
vector<int> dNums(vector<int> &a, int b)
{
    vector<int> ans;
    unordered_map<int, int> mp;
    for (int i = 0; i < b; i++)
    {
        mp[a[i]]++;
    }
    ans.push_back(mp.size());
    int j = 0;
    for (int i = b; i < a.size(); i++)
    {
        mp[a[j]]--;
        if (mp[a[j]] == 0)
            mp.erase(a[j]);
        mp[a[i]]++;
        ans.push_back(mp.size());
        j++;
    }
    return ans;
}
