void traverseLeft(TreeNode<int>* root,vector<int>& answer){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    answer.push_back(root->data);
    if(root->left!=NULL){
        traverseLeft(root->left,answer);
    }
    else{
        traverseLeft(root->right,answer);
    }
}
 
void traverseLeaf(TreeNode<int>* root,vector<int>& answer){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        answer.push_back(root->data);
        return;
    }
    traverseLeaf(root->left,answer);
    traverseLeaf(root->right,answer);
}
 
void traverseRight(TreeNode<int>* root,vector<int>& answer){
     if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
 
    if(root->right!=NULL){
        traverseRight(root->right,answer);
    }
    else{
        traverseRight(root->left,answer);
    }
    answer.push_back(root->data);
}
 
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
 
    ans.push_back(root->data);
    traverseLeft(root->left,ans);
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
    traverseRight(root->right,ans);
 
    return ans;
}