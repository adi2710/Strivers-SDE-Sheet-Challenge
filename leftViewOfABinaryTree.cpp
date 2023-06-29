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

void preorder(TreeNode<int> *root, int lvl, vector<int> &ans)
{
    if(root == nullptr)
        return;
    if(ans.size() < lvl)
        ans.push_back(root -> data);
    preorder(root -> left, lvl + 1, ans);
    preorder(root -> right, lvl + 1, ans);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ans;
    preorder(root, 1, ans);
    return ans;
}