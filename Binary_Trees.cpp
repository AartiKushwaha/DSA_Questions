//Postorder Iteratively
//pepcoding is love



//Striver is no less
///pre iterative---> ffirst push right then left
vector<int> preorderTraversal(TreeNode* root) {
    if(!root) return{};
    vector<int> ans;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();
        ans.push_back(node->val);
        st.pop();
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
    }
    return ans;
}



vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(true){
            if(node){
                st.push(node);
                node = node->left;
            }else{
                if(st.empty()) break;
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }



///iterative postorder two stacks

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        stack<TreeNode*>  st1;
        stack<int> st2;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* curr = st1.top();
            st1.pop();
            if(curr->left) st1.push(curr->left);
            if(curr->right) st1.push(curr->right);
            st2.push(curr->val);
        }
        while(!st2.empty()){
            ans.push_back(st2.top());
            st2.pop();
        }
        return ans;
    }
};
vector<int> postorderTraversal(TreeNode* root) {
    if(root==NULL) return {};
    stack<pair<TreeNode*, int>> st;
    vector<int> ans;//I am making this comment so that my streak doesn't break ;)
    st.push({root,1});
    while(!st.empty()){
        if(st.top().second==1){
            st.top().second++;
            if(st.top().first->left){
                st.push({st.top().first->left, 1});
            }
        }
        else if(st.top().second==2){

            st.top().second++;
            if(st.top().first->right){
                st.push({st.top().first->right, 1});
            }
        }
        else{
            ans.push_back(st.top().first->val);           //for preorder and this line to second==1 and for inoredr in 2
            st.pop();
        }
    }
    return ans;
}


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

//Node to leaf path

void solver(TreeNode* root, vector<string> &paths, string p){
    if(!root->left and !root->right) {
        paths.push_back(p);
        return;
    }
    if(root->left) solver(root->left, paths, p+"->"+to_string(root->left->val));
    if(root->right) solver(root->right, paths, p+"->"+to_string(root->right->val));
}

vector<string> binaryTreePaths(TreeNode* root) {
    if(root==NULL) return {};
    vector<string> ans;
    solver(root, ans, to_string(root->val));
    return ans;
}


//Print k levels down

void solver(struct Node* root, int k, vector<int> &ans){
    if(root==NULL || k<0) return;
    if(k==0){
        ans.push_back(root->data);
    }
    solver(root->left, k-1, ans);
    solver(root->right, k-1, ans);
}

vector<int> Kdistance(struct Node *root, int k)
{
  // Your code here
  if(root==NULL) return {};
  vector<int> ans;
  solver(root, k, ans);
  return ans;
  
}

//K distance far

void kLevelDown(TreeNode* root, int k, vector<int> &kFar, TreeNode* prev){
        if(root==NULL || k<0 || root==prev) return;
        if(k==0){
            kFar.push_back(root->val);
        }
        kLevelDown(root->left, k-1, kFar, prev);
        kLevelDown(root->right, k-1, kFar, prev);
    }
    
    bool rootToTarget(TreeNode* root, int target, vector<TreeNode*> &path){
        if(root==NULL) return false;
        if(root->val==target){
            path.push_back(root);
            return true;
        }
        bool l = rootToTarget(root->left, target, path);
        if(l){
            path.push_back(root);
            return true;
        } 
        bool r = rootToTarget(root->right, target, path);
        if(r){
            path.push_back(root);
            return true;
        } 
        return false;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        vector<TreeNode*> pathUptoTarget;
        bool temp = rootToTarget(root, target->val, pathUptoTarget);
        for(int i=0;i<pathUptoTarget.size();i++){
            kLevelDown(pathUptoTarget[i], k-i, ans, i==0?NULL:pathUptoTarget[i-1]);
        }
        return ans;
    }


//Remove leaves


TreeNode* removeLeafNodes(TreeNode* root, int target) {
    if(root==NULL) return NULL;

    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);
    if(root->left==NULL and root->right==NULL and root->val == target){
        return NULL;
    }
    return root;
}


//is balanced binary tree
bool isbal = true;
int check(TreeNode* root){
    if(root==NULL) return 0;
    int lh = check(root->left);
    int rh = check(root->right);

    int diff = abs(lh-rh);
    if(diff>1) isbal = false;

    return max(lh,rh)+1;
}
bool isBalanced(TreeNode* root) {
    if(root==NULL) return true;
    check(root);
    return isbal;
}


//is binary seach tree {normal recursion}
bool isBST(TreeNode* root, TreeNode* min, TreeNode* max){
    if(root==NULL) return true;
    if(min!=NULL and root->val <= min->val) return false;
    if(max!=NULL and root->val >= max->val) return false;
    bool leftCheck = isBST(root->left, min, root);
    bool rightCheck = isBST(root->right, root, max);
    return leftCheck && rightCheck;
}

bool isValidBST(TreeNode* root) {
    return isBST(root, NULL, NULL);
}


//using inorder property.....inorder traversal would be sorted If a tree is binary search tree

TreeNode* prev = NULL;
bool isValidBST(TreeNode* root) {
    if(root==NULL) return true;
    if(!isValidBST(root->left)) return false;
    if(prev!=NULL and prev->val >= root->val) return false;
    prev = root;
    if(!isValidBST(root->right)) return false;

    return true;
}


