#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

TreeNode<int>* buildTree(int l, int r, int &root, vector<int> &inorder, vector<int> &preorder)
{
    if(l > r)
        return nullptr;
    
    int mid = l;
    while(mid <= r && inorder[mid] != preorder[root]) mid++;
    TreeNode<int>* rootNode = new TreeNode<int> (inorder[mid]);
    root++;
    rootNode -> left = buildTree(l, mid - 1, root, inorder, preorder);
    rootNode -> right = buildTree(mid + 1, r, root, inorder, preorder);
    return rootNode;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    int root = 0;
    return buildTree(0, inorder.size() - 1, root, inorder, preorder);
}