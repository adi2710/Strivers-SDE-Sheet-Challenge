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

void floorInBST(TreeNode<int> *root, int X, int &ans)
{
    if(root == nullptr)
        return;
    if (root->val <= X) {
        ans = root->val;
        floorInBST(root->right, X, ans);
    }
    else
        floorInBST(root -> left, X, ans);
}

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int ans = 0;
    floorInBST(root, X, ans);
    return ans;
}