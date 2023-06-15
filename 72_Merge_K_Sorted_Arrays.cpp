#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)

{

    // Write your code here.

    priority_queue<pair<int, pair<int, int>>,

                   vector<pair<int, pair<int, int>>>,

                   greater<pair<int, pair<int, int>>>>
        pq;

    for (int i = 0; i < k; i++)

    {

        pq.push({kArrays[i][0], {i, 0}});
    }

    vector<int> ans;

    while (!pq.empty())

    {

        int val = pq.top().first;

        int row = pq.top().second.first;

        int col = pq.top().second.second;

        pq.pop();

        ans.push_back(val);

        if (col + 1 < kArrays[row].size())

            pq.push({kArrays[row][col + 1], {row, col + 1}});
    }

    return ans;
}