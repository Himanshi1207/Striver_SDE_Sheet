#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        while(low<=high){
            int mid=(high+low)>>1;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target){
                if(nums[low]<nums[mid] and target>=nums[low])
                    high=mid-1;
                else
                    low=mid+1;
            }
            else{
                if(nums[high]>nums[mid] and target<=nums[high])
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        return -1;
    }
};