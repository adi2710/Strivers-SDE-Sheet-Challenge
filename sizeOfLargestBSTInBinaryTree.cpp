#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

class info{
    public:
    int mx;
    int mn;
    bool isBST;
    int sz;
};

info solve(TreeNode<int> *root, int &ans)
{
    if(root == nullptr)
        return {INT_MIN, INT_MAX, true, 0};
    
    info left = solve(root -> left, ans);
    info right = solve(root -> right, ans);

    info cur;
    cur.mx = max(root -> data, right.mx);
    cur.mn = min(root -> data, left.mn);
    cur.sz = left.sz + right.sz + 1;
    if(left.isBST && right.isBST && left.mx < root -> data && root -> data < right.mn)
        ans = max(ans, cur.sz), cur.isBST = true;
    else
        cur.isBST = false;
    return cur;
}

int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int ans = 0;
    solve(root, ans);
    return ans;
}