#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

void inorder(BinaryTreeNode<int>* root, int &prev, int &key, pair<int, int> &ans)
{
    if(root == nullptr)
        return;
    inorder(root -> left, prev, key, ans);
    if(root -> data == key)
        ans.first = prev;
    if(prev == key)
        ans.second = root -> data;
    prev = root -> data;
    inorder(root -> right, prev, key, ans);
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    pair<int, int> ans = {-1, -1};
    int prev = -1;
    inorder(root, prev, key, ans);
    return ans;
}