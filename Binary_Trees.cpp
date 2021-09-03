//Level Order Traversal

vector<int> levelOrder(Node* root)
    {
        vector<int> ans;
        if(root==NULL) return ans;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* node=q.front();
            q.pop();
            if(node!=NULL){
                ans.push_back(node->data);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }else if(!q.empty()) q.push(NULL);
        }
        return ans;
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

