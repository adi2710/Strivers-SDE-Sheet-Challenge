#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    queue<pair<BinaryTreeNode<int>*, int>> q;
    q.push({root, 0});
    map<int, int> mp;
    while(!q.empty())
    {
        for(int i = q.size(); i >= 1; i--)
        {
            auto a = q.front();
            q.pop();
            mp[a.second] = a.first -> data;
            if(a.first -> left != nullptr)
                q.push({a.first -> left, a.second - 1});
            if(a.first -> right != nullptr)
                q.push({a.first -> right, a.second + 1});
        }
    }
    vector<int> ans;
    for(auto &x : mp)
        ans.push_back(x.second);
    return ans;
}
