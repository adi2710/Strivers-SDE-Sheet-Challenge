#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    TreeNode *cur = root;
    vector<int> ans;
    while(cur != nullptr)
    {
        if(cur -> left == nullptr)
        {
            ans.push_back(cur -> data);
            cur = cur -> right;
        }
        else
        {
            TreeNode *tmp = cur -> left;
            while(tmp -> right != nullptr && tmp -> right != cur)
                tmp = tmp -> right;
            if(tmp -> right == nullptr)
            {
                tmp -> right = cur;
                ans.push_back(cur -> data);
                cur = cur -> left;
            }
            else
            {
                tmp -> right = nullptr;
                cur = cur -> right;
            }
        }
    }
    return ans;
}