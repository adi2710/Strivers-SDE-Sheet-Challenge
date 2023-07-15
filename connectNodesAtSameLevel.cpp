#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    if(root == nullptr)
        return;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while(!q.empty())
    {
        for(int i = q.size(); i >= 1; i--)
        {
            BinaryTreeNode<int> *cur = q.front();
            q.pop();
            if(i > 1)
                cur -> next = q.front();
            if(cur -> left != nullptr)
                q.push(cur -> left);
            if(cur -> right != nullptr)
                q.push(cur -> right);
        }
    }
}