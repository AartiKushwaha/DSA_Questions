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
    
    int solver(TreeNode* root, int &ans){
        if(!root) return 0;
        
        int ls = max(0, solver(root->left, ans));
        int rs = max(0, solver(root->right, ans));
        
        ans = max(ans, ls+rs+(root->val));
        return max(ls, rs)+(root->val);
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solver(root, ans);
        return ans;
    }
};