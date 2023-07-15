#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

class BSTiterator
{
    stack<TreeNode<int> *> st;
    public:
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        pushAll(root);
    }

    void pushAll(TreeNode<int> *cur)
    {
        while(cur != nullptr)
        {
            st.push(cur);
            cur = cur -> left;
        }
    }

    int next()
    {
        // write your code here
        TreeNode<int> *cur = st.top();
        st.pop();
        pushAll(cur -> right);
        return cur -> data;
    }

    bool hasNext()
    {
        // write your code here
        if(st.empty())
            return false;
        return true;
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/