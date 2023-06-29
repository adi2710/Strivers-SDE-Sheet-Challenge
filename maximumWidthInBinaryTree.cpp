#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(root == nullptr)
        return 0;
    queue<TreeNode<int>*> q;
    q.push(root);
    int ans = 0;
    while(!q.empty())
    {
        ans = max(ans, (int)q.size());
        for(int i = q.size(); i >= 1; i--)
        {
            auto a = q.front();
            q.pop();
            if(a -> left != nullptr)
                q.push(a -> left);
            if(a -> right != nullptr)
                q.push(a -> right);
        }
    }
    return ans;
}