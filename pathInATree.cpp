#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/

void solve(TreeNode<int> *root, int x, vector<int> &path, vector<int> &ans)
{
	if(root == nullptr)
		return;
	if(!ans.empty())
		return;
	path.push_back(root -> data);
	if(root -> data == x)
	{
		ans = path;
		return;
	}
	solve(root -> left, x, path, ans);
	solve(root -> right, x, path, ans);
	path.pop_back();
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> ans, path;
	solve(root, x, path, ans);
	return ans;
}
