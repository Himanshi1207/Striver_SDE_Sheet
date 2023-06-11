#include<bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};


class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job &a, Job &b){
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, cmp);
        int maxdeadline=arr[0].dead;
        for(int i=1;i<n;i++)
            maxdeadline=max(maxdeadline, arr[i].dead);
        vector<int> available(maxdeadline+1, -1);
        int totalProfit=arr[0].profit;
        int noofjobs=1;
        available[arr[0].dead]=arr[0].id;
        for(int i=1;i<n;i++){
            int j=arr[i].dead;
            while(j>=1 and available[j]!=-1){
                j--;
            }
            if(j!=0){
                available[j]=arr[i].id;
                totalProfit+=arr[i].profit;
                noofjobs++;
            }
        }
        return {noofjobs, totalProfit};
    } 
};