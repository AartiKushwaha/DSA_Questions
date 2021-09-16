//Level Order Traversal

vector<vector<int>> levelOrder(TreeNode* root) {
    if(root==NULL) return {};
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> v;
        for(int i=0;i<size;i++){
            TreeNode* parent = q.front();
            q.pop();
            v.push_back(parent->val);
            if(parent->left) q.push(parent->left);
            if(parent->right) q.push(parent->right);
        }
        ans.push_back(v);
    }
    return ans;
}
  //This can be done using recursion as well
  
  // Reverse level oder traversal
  
  //using recursion
 int height(Node* root){
    if(root==NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh>rh?lh+1:rh+1);
}
void printLevel(Node* root, int lvl, vector<int> &ans){
    if(root==NULL) return;
    if(lvl == 1) ans.push_back(root->data);
    else if(lvl>1){
        printLevel(root->left,lvl-1,ans);
        printLevel(root->right,lvl-1,ans);
    }
}
vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
    int ht = height(root);
    for(int i=ht;i>=1;i--){
        printLevel(root, i, ans);
    }
    return ans;
    
}
  
// Same can be done for level oder traversal..the only change to be made is reversal for the for loop
  
//without Recursion
vector<int> reverseLevelOrder(Node *root)
{
    // code here
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    // q.push(NULL);
    while(!q.empty()){
        Node* n = q.front();
        if(n){
            ans.push_back(n->data);
            if(n->right) q.push(n->right);
            if(n->left) q.push(n->left);
        }else if(q.empty()) q.push(NULL);
        q.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
    
    
//diameter of binary tree

int height(TreeNode* root){
    if(root==NULL) return -1;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh,rh)+1;
}

int diameterOfBinaryTree(TreeNode* root) {
    if(root==NULL) return 0;
    int ld = diameterOfBinaryTree(root->left);
    int rd = diameterOfBinaryTree(root->right);
    int ir = height(root->left)+height(root->right)+2;
    return max(ir,max(ld,rd));
}
