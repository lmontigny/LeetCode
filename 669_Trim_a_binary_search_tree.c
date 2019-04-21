/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* trimBST(struct TreeNode* root, int L, int R) {
    if(!root) return NULL;
    
    // Court-circuit the traversal return pointer in a)
    // ex: if below the limit, it will not return the root but the root->right
    if(root->val < L) { return trimBST(root->right, L, R); }
    if(root->val > R) { return trimBST(root->left, L, R); }
    
    // a) Usual BST traversal 
    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);

    return root;
}
