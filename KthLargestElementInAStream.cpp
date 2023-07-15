#include <bits/stdc++.h> 
class Kthlargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
public:
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here.
       this -> k = k;
       for(int x : arr)
        {
            pq.push(x);
            if(pq.size() > k)
                pq.pop();
        }
    }

    void add(int num) {
        // Write your code here.
        pq.push(num);
        if(pq.size() > k)
            pq.pop();
    }

    int getKthLargest() {
       // Write your code here.
       return pq.top();
    }

};