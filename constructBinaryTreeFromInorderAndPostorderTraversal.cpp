/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/

TreeNode<int>* buildTree(int l, int r, int &root, vector<int> &inorder, vector<int> &postorder)
{
    if(l > r)
        return nullptr;
    
    int mid = l;
    while(mid <= r && inorder[mid] != postorder[root]) mid++;
    TreeNode<int>* rootNode = new TreeNode<int> (inorder[mid]);
    root--;
    rootNode -> right = buildTree(mid + 1, r, root, inorder, postorder);
    rootNode -> left = buildTree(l, mid - 1, root, inorder, postorder);
    return rootNode;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
	// Write your code here.
     int root = postorder.size() - 1;
     return buildTree(0, inorder.size() - 1, root, inorder, postorder);
}
