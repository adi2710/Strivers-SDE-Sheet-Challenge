#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    if(root == nullptr)
        return {};
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    vector<int> ans;
    while(!q.empty())
    {
        for(int i = q.size(); i >= 1; i--)
        {
            auto a = q.front();
            q.pop();
            ans.push_back(a -> val);
            if(a -> left != nullptr)
                q.push(a -> left);
            if(a -> right != nullptr)
                q.push(a -> right);
        }
    }
    return ans;
}