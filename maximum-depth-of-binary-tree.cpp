// 104. Maximum Depth of Binary Tree

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int depth_left = maxDepth(root->left) + 1;
        int depth_right = maxDepth(root->right) + 1;
        return depth_left > depth_right ? depth_left : depth_right;
        //return (maxDepth(root->left) > maxDepth(root->right))? maxDepth(root->left) : maxDepth(root->right);  
    }
};
