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

void reverseInorder(TreeNode<int> *root, int &k, int &ans)
{
    if(root == nullptr || k < 0)
        return;
    reverseInorder(root -> right, k, ans);
    k--;
    if (k == 0)
        ans = root -> data;
    reverseInorder(root -> left, k, ans);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    int ans = -1;
    reverseInorder(root, k, ans);
    return ans;
}
