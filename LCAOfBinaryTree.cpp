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

int findLCA(TreeNode<int> *root, int x, int y, int &ans)
{
    if(root == nullptr)
        return -1;
    if(ans != -1)
        return -1;
    int lf = findLCA(root -> left, x, y, ans);
    int rt = findLCA(root -> right, x, y, ans);
    int val = root -> data;
    if((val == x && (lf == y || rt == y)) || (val == y && (lf == x || rt == x)) || (lf == x && rt == y) || (lf == y && rt == x)){
        ans = root -> data;
        return -1;
    }
    if(root -> data == x)
        return x;
    else if(root -> data == y)
        return y;
    return max(lf, rt);
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    int ans = -1;
    findLCA(root, x, y, ans);
    return ans;
}