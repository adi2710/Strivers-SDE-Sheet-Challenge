#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    if(root == nullptr)
        return {};
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});
    map<int, int> mp;
    while(!q.empty())
    {
        for(int i = q.size(); i >= 1; i--)
        {
            auto a = q.front();
            q.pop();
            if(mp.find(a.second) == mp.end())
                mp[a.second] = a.first -> val;
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