#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

void findCeil(BinaryTreeNode<int> *root, int X, int &ans)
{
    if(root == nullptr)
        return;
    if (root -> data >= X) {
        ans = root -> data;
        findCeil(root -> left, X, ans);
    }
    else
        findCeil(root -> right, X, ans);
}

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ans = -1;
    findCeil(node, x, ans);
    return ans;
}