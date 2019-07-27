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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return NULL;
        
        // Traverse graph        
        if(val<root->val) root->left = insertIntoBST(root->left, val);
        else root->right = insertIntoBST(root->right, val);
        
        // Leaf node
        if(!root->left && !root->right){
            if(val>root->val){
                TreeNode* tmp = new TreeNode(val);
                root->right = tmp;
            }
            else{
                TreeNode* tmp = new TreeNode(val);
                root->left = tmp;
            }
        }
        // Empty left branch
        else if(!root->left && root->right && val<root->val){
            TreeNode* tmp = new TreeNode(val);
            root->left = tmp;
        }
        // Empty right branch
        else if(!root->right && root->left && val>root->val){
            TreeNode* tmp = new TreeNode(val);
            root->right = tmp;
        }

        return root;
    }
};
