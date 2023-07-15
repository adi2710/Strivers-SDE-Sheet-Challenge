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

bool findLeaf(TreeNode<int> *root, TreeNode<int> *leaf, stack<TreeNode<int> *> &st)
{
    if(root == nullptr)
        return false;
    if(root -> data == leaf -> data)
    {
        st.push(root);
        return true;
    }
    st.push(root);
    bool lf = findLeaf(root -> left, leaf, st);
    bool rt = findLeaf(root -> right, leaf, st);
    if(!lf && !rt)
        st.pop();
    return lf || rt;
}

TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
	// Write your code here.
    stack<TreeNode<int> *> st;
    findLeaf(root, leaf, st);
    root = st.top();
    TreeNode<int> *cur = st.top();
    st.pop();
    while(!st.empty())
    {
        TreeNode<int> *par = st.top();
        st.pop();
        if(cur == par -> left)
            par -> left = nullptr;
        else{
            par -> right = par -> left;
            par -> left = nullptr;
        }
        cur -> left = par;
        cur = par;
    }
    return root;
}
