/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#ifndef max
	#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#endif

/* 
read from bottom and go up
check if every node has depth<=1
   3
   / \
  9  20
    /  \
   15   7
stdout
1, 2 
0, 0 
1, 1 
0, 0 
0, 0 
*/

int height(struct TreeNode* root) {
    if(!root) return 0;
    
    int left = height(root->left);
    int right = height(root->right);
    return max(left,right)+1;
}

bool isBalanced(struct TreeNode* root) {
        if(!root) return true;
        int left_height = height(root->left);
        int right_height = height(root->right);
        //printf("%u, %u \n", left_height, right_height);
    
        return (abs(left_height - right_height)<=1) && isBalanced(root->left) && isBalanced(root->right);
}
