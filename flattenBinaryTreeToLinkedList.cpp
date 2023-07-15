#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    TreeNode<int> *cur = root;
    while(cur != nullptr)
    {
        if(cur -> left == nullptr)
            cur = cur -> right;
        else
        {
            TreeNode<int> *tmp = cur -> left;
            while(tmp -> right != nullptr)
                tmp = tmp -> right;
            tmp -> right = cur -> right;
            cur -> right = cur -> left;
            cur = cur -> right;
        }
    }
    return root;
}