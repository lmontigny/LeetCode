// 617. Merge Two Binary Trees

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 && t2){
            TreeNode* sum = new TreeNode(t1->val+t2->val);
            sum->left  = mergeTrees(t1->left, t2->left);
            sum->right = mergeTrees(t1->right, t2->right);
            return sum;
        }
        else{
            return t1 ? t1: t2;
        }
   
    }
};
