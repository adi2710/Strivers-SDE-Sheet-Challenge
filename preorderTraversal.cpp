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
    stack<TreeNode*> st;
    TreeNode *cur = root;
    vector<int> ans;
    while(!st.empty() || cur != nullptr)
    {
        while(cur != nullptr)
        {
            ans.push_back(cur -> data);
            st.push(cur);
            cur = cur -> left;
        }
        cur = st.top();
        st.pop();
        cur = cur -> right;
    }
    return ans;
}