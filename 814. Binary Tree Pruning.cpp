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
    /*
    !!BAD!!
    int traverse(TreeNode* root){
        if(!root) return 0;
        
        int left = traverse(root->left);
        int right = traverse(root->right);
        
        if(left==0 && (right==1 || !right)) 
           root->left = NULL;
        if((left==1 || !left) && right==0) 
           root->right = NULL;
        
        return root->val;
    }
    */
    
    
    /* Note
    /* delete only the current node, and return NULL if one to be deleted
    /* condition: if root->val==0, need another condition otherwise will delete all val=0
    /* the other condition: if this node is leaf
    */
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return NULL;
        
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        
        if(!root->left && !root->right && root->val==0) 
            root = NULL;
        
        return root;
    }
};
