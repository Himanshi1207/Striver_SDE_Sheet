#include<bits/stdc++.h>
using namespace std;
int books(vector<int> &a, int b) {
    int sum=0;
    int mx=0;
    int n=a.size();
    if(n<b)
    return -1;
    for(int i=0;i<n;i++){
        sum+=a[i];
        mx=max(mx, a[i]);
    }
    int low=mx, high=sum, ans=-1;
    while(low<=high){
        int mid=(low+high)>>1;
        bool possible;
        int student=1, pages=0;
        for(int i=0;i<n;i++){
            pages+=a[i];
            if(pages>mid){
                ++student;
                pages=a[i];
            }
        }
        if(student<=b){
            ans=mid;
            high=mid-1;
        }
        else
        low=mid+1;
    }
    return ans;
}
