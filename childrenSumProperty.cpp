#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void increaseSum(BinaryTreeNode<int> *root)
{
    if(root == nullptr)
        return;
    int lf = root -> left == nullptr ? 0 : root -> left -> data;
    int rt = root -> right == nullptr ? 0 : root -> right -> data;
    if(lf == 0 && rt == 0)
        return;
    if(lf > 0 && rt > 0)
    {
        if(lf < rt)
        {
            root -> left -> data = root -> data - rt;
            increaseSum(root -> left);
        }
        else
        {
            root -> right -> data = root -> data - lf;
            increaseSum(root -> right);
        }

    }
    else if(rt == 0){
        root -> left -> data = root -> data - rt;
        increaseSum(root -> left);
    }
    else{
        root -> right -> data = root -> data - lf;
        increaseSum(root -> right);
    }
}

void changeTree(BinaryTreeNode<int> *root) {
    // Write your code here.
    if(root == nullptr)
        return;
    changeTree(root -> left);
    changeTree(root -> right);
    int lf = root -> left == nullptr ? 0 : root -> left -> data;
    int rt = root -> right == nullptr ? 0 : root -> right -> data;
    if(root -> data > lf + rt)
        increaseSum(root);
    else
        root -> data = lf + rt;
}  