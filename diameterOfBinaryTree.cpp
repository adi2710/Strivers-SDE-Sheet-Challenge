/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int solve(TreeNode<int> *root, int &ans)
{
    if(root == nullptr)
        return 0;
    int lf = solve(root -> left, ans);
    int rt = solve(root -> right, ans);
    ans = max(ans, lf + rt);
    return max(lf, rt) + 1;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    int ans = 0;
    solve(root, ans);
    return ans;
}
