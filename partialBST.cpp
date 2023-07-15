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

void check(BinaryTreeNode<int> *root, int &prev, bool &ans)
{
    if(root == nullptr)
        return;
    check(root -> left, prev, ans);
    if(prev <= root -> data){
        prev = root -> data;
        check(root -> right, prev, ans);
    }
    else
        ans = false;
}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    int prev = INT_MIN;
    bool ans = true;
    check(root, prev, ans);
    return ans;
}