#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/

class BSTiterator
{
    stack<BinaryTreeNode<int> *> st;
    bool isReverse;
    public:
    BSTiterator(BinaryTreeNode<int> *root, bool isReverse)
    {
        // write your code here
        this -> isReverse = isReverse;
        pushAll(root);
    }

    void pushAll(BinaryTreeNode<int> *cur)
    {
        while(cur != nullptr)
        {
            st.push(cur);
            if(!isReverse)
                cur = cur -> left;
            else
                cur = cur -> right;
        }
    }

    void next()
    {
        // write your code here
        BinaryTreeNode<int> *cur = st.top();
        st.pop();
        if(!isReverse)
            pushAll(cur -> right);
        else
            pushAll(cur -> left);
    }

    BinaryTreeNode<int> * nodeNext()
    {
        // write your code here
        if(!st.empty())
            return st.top();
        return nullptr;
    }
};

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    BSTiterator *l = new BSTiterator(root, false);
    BSTiterator *r = new BSTiterator(root, true);
    while(l -> nodeNext() != r -> nodeNext())
    {
        if(l -> nodeNext() -> data + r -> nodeNext() -> data == k)
            return true;
        else if(l -> nodeNext() -> data + r -> nodeNext() -> data < k)
            l -> next();
        else
            r -> next();
    }
    return false;
}