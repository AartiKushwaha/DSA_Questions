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
    TreeNode* solver(TreeNode* root, TreeNode* tail){
        if (!root) return tail;
        TreeNode* res = solver(root->left, root);
        root->left = NULL;
        root->right = solver(root->right, tail);
        return res;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        return solver(root, NULL);
    }
};