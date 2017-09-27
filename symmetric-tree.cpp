class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return helper(root->left, root->right);
    }
    
    bool checkSim(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        } else if (!p || !q) {
            return false;
        }
        
        if (p->val != q->val) {
            return false;
        }
        
        return checkSim(p->left,q->right) && helper(p->right, q->left); 
    }
};
