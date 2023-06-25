#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)

{
    sort(arr.begin(), arr.end());

    int max = arr[k - 1];

    int min = arr[n - k];

    vector<int> v;

    v.push_back(max);

    v.push_back(min);

    return v;
}