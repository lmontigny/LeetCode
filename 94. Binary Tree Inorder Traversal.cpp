/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> res;
public:
    void traversal(TreeNode* root){
        if(!root) return;
        traversal(root->left);
        res.push_back(root->val);
        traversal(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        traversal(root);
        return res;         
    }
};
