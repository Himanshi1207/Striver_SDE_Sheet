#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
long long int merge1(long long int a[], long long int temp[], long long int left, long long int mid, long long int right){
        long long int i,k,j,inv=0;
        i=left;
        j=mid;
        k=left;
        while((i<=mid-1) and (j<=right)){
            if(a[i]<=a[j]){
                temp[k++]=a[i++];
            }
            else{
                temp[k++]=a[j++];
                inv+=(mid-i);
            }
        }
        while(i<=mid-1){
            temp[k++]=a[i++];
        }
        while(j<=right){
            temp[k++]=a[j++];
        }
        for(int m=left;m<=right;m++){
            a[m]=temp[m];
        }
        return inv;
    }
    long long int mergesort(long long int a[], long long int temp[], long long int left,long long int right){
        long long int inv=0;
        if(left<right){
            long long int mid=(left+right)/2;
            inv+=mergesort(a, temp, left, mid);
            inv+=mergesort(a, temp, mid+1, right);
            inv+=merge1(a, temp, left, mid+1, right);
        }
        return inv;
    }
    long long int getInversions(long long arr[], long long n)
    {
        // Your Code Here
        long long temp[n];
        return mergesort(arr, temp, 0, n-1);
        
    }