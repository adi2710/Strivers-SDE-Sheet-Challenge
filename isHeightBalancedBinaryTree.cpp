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

int solve(BinaryTreeNode<int>* root, bool &ans)
{
    if(root == nullptr)
        return 0;
    int lf = solve(root -> left, ans);
    int rt = solve(root -> right, ans);
    if(abs(lf - rt) > 1)
        ans = false;
    return max(lf, rt) + 1;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    bool ans = true;
    solve(root, ans);
    return ans;
}