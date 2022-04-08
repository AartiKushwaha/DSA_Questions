/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void solver(TreeNode* root, int level, vector<int> &ans){
        //reverse preorder traversal
        
        if(root == NULL) return;
        if(level == ans.size()) ans.push_back(root->val);
        solver(root->right, level+1, ans);
        solver(root->left, level+1, ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans;
        solver(root, 0, ans);
        return ans;
    }
};