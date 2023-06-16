#include <bits/stdc++.h> 
// Stack class.
class Stack {
    vector<int> st;
    int topp;
public:
    
    Stack(int capacity) {
        // Write your code here.
        st.resize(capacity);
        topp = -1;
    }

    void push(int num) {
        // Write your code here.
        if(topp + 1 == st.size())
            return;
        st[++topp] = num;
    }

    int pop() {
        // Write your code here.
        if(topp == -1)
            return -1;
        int a = st[topp--];
        return a;
    }
    
    int top() {
        // Write your code here.
        if(topp == -1)
            return -1;
        return st[topp];
    }
    
    int isEmpty() {
        // Write your code here.
        if(topp == -1)
            return 1;
        return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(topp + 1 == st.size())
            return 1;
        return 0;
    }
    
};