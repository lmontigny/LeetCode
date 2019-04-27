/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void helper(struct TreeNode* root, int* sum){
    if(!root) return;
    
    helper(root->right, sum);
    root->val += *sum;
    *sum = root->val;
    helper(root->left, sum);

}

struct TreeNode* convertBST(struct TreeNode* root) {
    if(!root) return NULL;
    
    int sum = 0;
    helper(root, &sum);  
    return root;    
}
