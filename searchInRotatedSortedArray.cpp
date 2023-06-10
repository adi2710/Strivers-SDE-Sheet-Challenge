int search(int* arr, int n, int key) {
    // Write your code here.
    int l = 0, r = n - 1;
    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        if(arr[mid] == key)
            return mid;
        bool isGreater = arr[0] <= arr[mid];
        bool isKeyGreater = arr[0] <= key;
        if(isGreater == isKeyGreater)
        {
            if(arr[mid] < key)
                l = mid + 1;
            else
                r = mid - 1;
        }
        else
        {
            if(isGreater)
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return -1;
}