// TC-O(n)
// SC-O(n)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int s) {
        unordered_map<int,int> freq;

       for(int i=0;i<arr.size();i++){
          int target=s-arr[i];
          if(freq.find(target)!=freq.end()){
             return{i, freq[target]};
          }
          freq[arr[i]]=i;
       }
        return {};
    }
};