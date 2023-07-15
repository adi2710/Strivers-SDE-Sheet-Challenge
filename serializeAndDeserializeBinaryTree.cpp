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

string serializeTree(TreeNode<int> *root)
{
    // Write your code here for serializing the tree
    string ans;
    queue<TreeNode<int> *> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode<int> *cur = q.front();
        q.pop();
        if(cur == nullptr)
        {
            ans += "-1 ";
            continue;
        }
        else
            ans += to_string(cur -> data) + " ";
        q.push(cur -> left);
        q.push(cur -> right);
    }
    return ans;
}

TreeNode<int>* deserializeTree(string &serialized)
{
    // Write your code here for deserializing the tree
    // cout << serialized << endl;
    vector<int> levelOrder;
    int n = serialized.size();
    for(int i = 0; i < n; i++)
    {
        int num = 0, sign = 1;
        if(serialized[i] == '-')
            sign = -1, i++;
        while (i < n && serialized[i] != ' ') {
            num = num * 10 + serialized[i] - '0';
            i++;
        }
        if(sign == -1)
            levelOrder.push_back(-1);
        else
            levelOrder.push_back(num);
    }
    if(levelOrder[0] == -1)
        return nullptr;
    TreeNode<int> *root = new TreeNode<int>(levelOrder[0]);
    n = levelOrder.size();
    queue<TreeNode<int> *> q;
    q.push(root);
    for(int i = 0, j = 1; j < n; i++)
    {
        TreeNode<int> *cur = q.front();
        q.pop();
        if(cur == nullptr)
            continue;
        cur -> left = levelOrder[j] == -1 ? nullptr : new TreeNode<int>(levelOrder[j]);
        j++;
        cur -> right = levelOrder[j] == -1 ? nullptr : new TreeNode<int>(levelOrder[j]);
        j++;
        q.push(cur -> left);
        q.push(cur -> right);
    }
    return root;
}