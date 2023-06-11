#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        if(n==0) return 0;
        int count=1;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
            v.push_back({end[i],start[i]});
        sort(v.begin(), v.end());
        int i=0;
        int j=1;
        while(i<n and j<n){
            if(v[i].first<v[j].second){
                count++;
                i=j;
                j++;
            }
            else
                j++;
        }
        return count;
    }
};