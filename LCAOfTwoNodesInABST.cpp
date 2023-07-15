#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	// Write your code here
    if(P -> data > Q -> data)
        return LCAinaBST(root, Q, P);
    if(root == nullptr)
        return nullptr;
    if(P -> data <= root -> data && root -> data <= Q -> data)
        return root;
    else if(root -> data < P -> data)
        return LCAinaBST(root -> right, P, Q);
    return LCAinaBST(root -> left, P, Q);
}