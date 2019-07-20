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
    int sum = 0;
    public:
    int findTilt(TreeNode* root) {
        traverse(root);   
        return sum;
    }
    int traverse(TreeNode* root){
        if(!root) return 0;
        int left = traverse(root->left);
        int right = traverse(root->right);
        sum += abs(left-right);
        
        // otherwise, for leaf node, it return 0 with just left+right
        return root->val + left + right;
        }
};
