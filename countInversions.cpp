#include <bits/stdc++.h>

long long merge(int l, int mid, int r, long long arr[])
{
    long long count = 0;
    int i = l, j = mid + 1, k = 0;
    vector<long long> temp(r - l + 1);
    while(i <= mid && j <= r)
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else{
            count += mid - i + 1;
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid)
        temp[k++] = arr[i++];
    while(j <= r)
        temp[k++] = arr[j++];
    for(int pos = l; pos <= r; pos++)
        arr[pos] = temp[pos - l];
    return count;
}

long long mergeSort(int l, int r, long long arr[])
{
    if (l == r)
        return 0;
    int mid = l + (r - l) / 2;
    long long count1 = mergeSort(l, mid, arr);
    long long count2 = mergeSort(mid + 1, r, arr);
    long long count3 = merge(l, mid, r, arr);
    return count1 + count2 + count3;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    return mergeSort(0, n - 1, arr);
}