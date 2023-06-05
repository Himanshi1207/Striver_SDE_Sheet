// TC-O(log(n+m))
// SC-O(1)
#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    void swaps(vector<int> &nums1, vector<int> &nums2, int ind1, int ind2){
        if(nums1[ind1]>nums2[ind2]){
            swap(nums1[ind1], nums2[ind2]);
        }
    }
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        if(m==0)
            return;
        if(n==0)
        {
            nums1=nums2;
            return;
        }
        int len=(m+n);
        int gap=(len/2)+(len%2);   
        while(gap>0){
            int left=0;
            int right=left+gap;
            while(right<len){
//                 arr1 and arr2
                if(left<n and right>=n){
                    swaps(nums1, nums2, left, right-n);
                }
//                 arr2 and arr2
                else if(left>=n){
                    swaps(nums2, nums2, left-n, right-n);
                }
//                 arr1 and arr1
                else{
                    swaps(nums1, nums1, left, right);
                }
                left++, right++;
            }
            if(gap==1)
                break;
            gap=(gap/2)+(gap%2);
        }
        int j=0;
        cout<<endl;
        for(int i=n;i<(m+n);i++){
            nums1[i]=nums2[j++];
        }
    }
};