#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
void delete_from_heap(vector<int> &ans, vector<int> &heap)
{
    if (heap.size() == 1)
        return;
    ans.push_back(heap[1]);
    heap[1] = heap.back();
    heap.pop_back();
    if (heap.size() == 1)
        return;
    int root = 1;
    while (root < heap.size())
    {
        int left = 2 * root;
        int right = 2 * root + 1;
        int swap_idx = root;
        if (left < heap.size() && heap[left] < heap[root])
        {
            swap_idx = left;
        }
        if (right < heap.size() && heap[right] < heap[swap_idx])
        {
            swap_idx = right;
        }
        if (swap_idx != root)
        {
            swap(heap[swap_idx], heap[root]);
            root = swap_idx;
        }
        else
            return;
    }
}
void create_min_heap(int val, vector<int> &heap)
{
    heap.push_back(val);
    int idx = heap.size() - 1;
    while (idx > 1)
    {
        int par = idx / 2;
        if (heap[par] > heap[idx])
        {
            swap(heap[par], heap[idx]);
            idx = par;
        }
        else
        {
            return;
        }
    }
}
vector<int> minHeap(int n, vector<vector<int>> &q)
{
    vector<int> heap;
    heap.push_back(-1);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (q[i].size() == 2)
        {
            create_min_heap(q[i][1], heap);
        }
        else
        {
            delete_from_heap(ans, heap);
        }
    }
    return ans;
}