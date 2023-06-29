#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    if(root == nullptr)
        return {};
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});
    map<int, vector<int>> mp;
    while(!q.empty())
    {
        for(int i = q.size(); i >= 1; i--) {
            auto a = q.front();
            q.pop();
            mp[a.second].push_back(a.first->data);
            if(a.first -> left != nullptr)
                q.push({a.first -> left, a.second - 1});
            if(a.first -> right != nullptr)
                q.push({a.first -> right, a.second + 1});
        }
    }
    vector<int> ans;
    for(auto &x : mp)
    {
        for(int &num : x.second)
            ans.push_back(num);
    }
    return ans;
}