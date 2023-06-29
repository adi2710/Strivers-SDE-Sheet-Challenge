#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

vector<int> inorder(BinaryTreeNode<int> *root)
{
    stack<BinaryTreeNode<int>*> st;
    BinaryTreeNode<int> *cur = root;
    vector<int> ans;
    while(!st.empty() || cur != nullptr)
    {
        while(cur != nullptr)
        {
            st.push(cur);
            cur = cur -> left;
        }
        cur = st.top();
        st.pop();
        ans.push_back(cur -> data);
        cur = cur -> right;
    }
    return ans;
}

vector<int> preorder(BinaryTreeNode<int> *root)
{
    stack<BinaryTreeNode<int>*> st;
    BinaryTreeNode<int> *cur = root;
    vector<int> ans;
    while(!st.empty() || cur != nullptr)
    {
        while(cur != nullptr)
        {
            ans.push_back(cur -> data);
            st.push(cur);
            cur = cur -> left;
        }
        cur = st.top();
        st.pop();
        cur = cur -> right;
    }
    return ans;
}

vector<int> postorder(BinaryTreeNode<int> *root)
{
    stack<BinaryTreeNode<int>*> st;
    BinaryTreeNode<int> *cur = root;
    vector<int> ans;
    while(!st.empty() || cur != nullptr)
    {
        while(cur != nullptr)
        {
            if(cur -> right != nullptr)
                st.push(cur -> right);
            st.push(cur);
            cur = cur -> left;
        }
        cur = st.top();
        st.pop();
        if(!st.empty() && st.top() == cur -> right)
        {
            BinaryTreeNode<int> *tmp = st.top();
            st.pop();
            st.push(cur);
            cur = tmp;
        }
        else
        {
            ans.push_back(cur -> data);
            cur = nullptr;
        }
    }
    return ans;
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    return {inorder(root), preorder(root), postorder(root)};
}