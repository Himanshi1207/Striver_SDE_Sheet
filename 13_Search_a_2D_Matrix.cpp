// TC-O(m+n)
// SC-O(1)
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(), col=matrix[0].size();
        int srow=row-1, scol=0;
        while(srow>=0 and srow<row and scol>=0 and scol<col){
            if(matrix[srow][scol]==target)
                return true;
            else if(matrix[srow][scol]<target){
                scol++;
            }
            else{
                srow--;
            }
        }
        return false;
    }
};