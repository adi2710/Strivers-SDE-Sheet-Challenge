#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

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

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> ans;
    if(root == nullptr)
        return ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    int lvl = 0;
    while(!q.empty())
    {
        vector<int> v;
        lvl++;
        for(int i = q.size(); i >= 1; i--)
        {
            auto cur = q.front();
            q.pop();
            v.push_back(cur -> data);
            if(cur -> left != nullptr)
                q.push(cur -> left);
            if(cur -> right != nullptr)
                q.push(cur -> right); 
        }
        if(lvl & 1 ^ 1)
        {
            for(int i = v.size() - 1; i >= 0; i--)
                ans.push_back(v[i]);
        }
        else
        {
            for(int i = 0; i < v.size(); i++)
                ans.push_back(v[i]);
        }
    }
    return ans;
}
