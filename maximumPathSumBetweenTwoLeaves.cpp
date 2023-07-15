#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

long long maxSum(TreeNode<int> *root, long long &ans)
{
    if(root == nullptr)
        return -1;
    
    long long lf = maxSum(root -> left, ans);
    long long rt = maxSum(root -> right, ans);

    if(lf != -1 && rt != -1)
        ans = max(ans, lf + rt + root -> val);
    if (lf == -1 && rt == -1)
        return root -> val;
    return max(lf, rt) + root -> val;
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    long long ans = -1;
    maxSum(root, ans);
    return ans;
}