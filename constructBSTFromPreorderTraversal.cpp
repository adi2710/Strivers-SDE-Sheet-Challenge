#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

TreeNode<int> *convertBST(int l, int r, vector<int> &preorder)
{
    if(l > r)
        return nullptr;
    TreeNode<int> *root = new TreeNode<int> (preorder[l]);
    int mid = l;
    while(mid + 1 <= r && preorder[mid + 1] < preorder[l]) mid++;
    root -> left = convertBST(l + 1, mid, preorder);
    root -> right = convertBST(mid + 1, r, preorder);
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    return convertBST(0, preOrder.size() - 1, preOrder);
}