#include<bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty() and minheap.empty())
            maxheap.push(num);
        else{
            if(maxheap.top()<num)
                minheap.push(num);
            else
                maxheap.push(num);
        }
        int n=maxheap.size();
        int m=minheap.size();
        if(n-m==2 or n-m==-2){
            if(n>m){
                int element=maxheap.top();
                maxheap.pop();
                minheap.push(element);
            }
            else{
              int element=minheap.top();
                minheap.pop();
                maxheap.push(element);
            }
        }
    }
    
    double findMedian() {
        int n=maxheap.size();
        int m=minheap.size();
        if((n-m)%2==0){
            return ((double)maxheap.top()+minheap.top())/2.0;
        }
        if(n>m)
            return maxheap.top();
        return minheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */