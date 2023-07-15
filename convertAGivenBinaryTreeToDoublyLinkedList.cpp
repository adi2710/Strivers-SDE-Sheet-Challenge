#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    BinaryTreeNode<int>* cur = root, *prev = nullptr;
    while(cur != nullptr)
    {
        if(cur -> left == nullptr){
            if(prev == nullptr)
                root = cur;
            else
                prev -> right = cur;
            cur -> left = prev;
            prev = cur;
            cur = cur -> right;
        }
        else
        {
            BinaryTreeNode<int>* tmp = cur -> left;
            while(tmp -> right != nullptr && tmp -> right != cur)
                tmp = tmp -> right;
            
            if(tmp -> right == nullptr){
                tmp -> right = cur;
                cur  = cur -> left;
            }
            else{
                if(prev == nullptr)
                    root = cur;
                else
                    prev -> right = cur;
                cur -> left = prev;
                prev = cur;
                cur = cur -> right;
            }
        }
    }
    return root;
}