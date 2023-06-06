#include <bits/stdc++.h>

void merge(int l, int mid, int r, vector<int> &arr)
{
    int i = l, j = mid + 1, k = 0;
    vector<int> temp(r - l + 1);
    while(i <= mid && j <= r)
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while(i <= mid)
        temp[k++] = arr[i++];
    while(j <= r)
        temp[k++] = arr[j++];
    for(int pos = l; pos <= r; pos++)
        arr[pos] = temp[pos - l];
}

int countPairs(int l, int mid, int r, vector<int> &arr)
{
    int count = 0;
    int j = mid + 1;
    for (int i = l; i <= mid; i++) {
        while (j <= r && arr[i] > 2 * arr[j]) j++;
        count += j - mid - 1;
    }
    return count;
}

int mergeSort(int l, int r, vector<int> &arr)
{
    if (l == r)
        return 0;
    int mid = l + (r - l) / 2;
    int count1 = mergeSort(l, mid, arr);
    int count2 = mergeSort(mid + 1, r, arr);
    int count3 = countPairs(l, mid, r, arr);
	merge(l, mid, r, arr);
    return count1 + count2 + count3;
}

int reversePairs(vector<int> &arr, int n){
    // Write your code here. 
	return mergeSort(0, n - 1, arr);   
}