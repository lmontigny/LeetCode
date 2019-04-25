/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int min(int a, int b){
    return (a < b)? a : b;
}

// InOrder BST return sorted array
// (left, root, right)
// Check min value on the root step
void inorder(struct TreeNode* root, int* previous, int* result){  
    if(!root) return;
    
    inorder(root->left, previous, result);
    if(*previous != -1) *result = min(*result, root->val - *previous);
    *previous = root->val;
    inorder(root->right, previous, result);
}

int getMinimumDifference(struct TreeNode* root) {
    if(!root) return -1;
    int result = INT_MAX;
    int previous = -1;
    
    inorder(root, &previous, &result);
    return result;
}
