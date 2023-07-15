#include <bits/stdc++.h>
using namespace std;
vector<int> minHeap(int n, vector<vector<int>>& queries) {
    // Write your code here.
    vector<int> heap;
    vector<int> ans;
    for(auto &q : queries)
    {
        if(q[0] == 0)
        {
            heap.push_back(q[1]);
            int pos = heap.size() - 1;
            while(pos > 0)
            {
                int par = (pos - 1) / 2;
                if(heap[par] > heap[pos])
                    swap(heap[par], heap[pos]), pos = par;
                else
                    break;
            }
        }
        else{
            ans.push_back(heap[0]);
            int pos = 0;
            heap[0] = heap.back();
            heap.pop_back();
            while(pos * 2 + 1 < heap.size())
            {
                int smallest = pos * 2 + 1;
                if(pos * 2 + 2 < heap.size() && heap[smallest] > heap[pos * 2 + 2])
                    smallest = pos * 2 + 2;
                if (heap[pos] > heap[smallest]) {
                    swap(heap[pos], heap[smallest]);
                    pos = smallest;
                }
                else
                    break;
            }
        }
    }
    return ans;
}