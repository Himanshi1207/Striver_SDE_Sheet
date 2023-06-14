#include<bits/stdc++.h>
using namespace std;
int countSmallerThanMid(vector<int> &a, int mid){
    int low=0, high=a.size()-1;
    while(low<=high){
        int md=(low+high)>>1;
        if(a[md]<=mid){
            low=md+1;
        }
        else{
            high=md-1;
        }
    }
    return low;
}
int findMedian(vector<vector<int> > &A) {
    int low=1;
    int high=1e9;
    int n=A.size();
    int m=A[0].size();
    while(low<=high){
        int mid=(low+high)>>1;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=countSmallerThanMid(A[i],mid);
        }
        if(cnt<=(n*m)/2) low=mid+1;
        else high=mid-1;
    }
    return low;
}