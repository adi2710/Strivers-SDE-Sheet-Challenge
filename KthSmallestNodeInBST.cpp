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

void solve(TreeNode<int> *root, int &k, int &ans)
{
    if(root == nullptr || k == 0)
        return;
    solve(root -> left, k, ans);
    k--;
    if(k == 0)
        ans = root -> data;
    solve(root -> right, k, ans);
}

int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    int ans = -1;
    solve(root, k, ans);
    return ans;
}