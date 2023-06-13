#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            pair<int,int>p = make_pair(end[i],start[i]);
            vec.push_back(p);
        }
        sort(vec.begin(),vec.end());
        int count = 0;
        int prev = -1;
        for(int i=0;i<n;i++)
        {
            if(prev<vec[i].second){
            count++;
            prev=vec[i].first;
            }
        }
        return count;
    }
};