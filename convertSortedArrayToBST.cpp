#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int>* sortedArrToBST(int l, int r, vector<int> &arr)
{
    if(l > r)
        return nullptr;
    int mid = l + (r - l) / 2;
    TreeNode<int> *root = new TreeNode<int>(arr[mid]);
    root -> left = sortedArrToBST(l, mid - 1, arr);
    root -> right = sortedArrToBST(mid + 1, r, arr);
    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return sortedArrToBST(0, n - 1, arr);
}