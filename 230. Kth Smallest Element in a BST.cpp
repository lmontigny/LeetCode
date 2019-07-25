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
    int count = 0;
    int global_min = INT_MIN;
    int kth = -1;
    bool done = false;
    
    void traverse(TreeNode* root, int k){
        if(!root || done) return;
        traverse(root->left, k);
        // Counter kth min value
        int previous_min = global_min;
        if(root->val > global_min) count++;

        // Compare counter value to k
        if(count==k) {
            kth = root->val;
            done = true;
            //return;
        }
        traverse(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        traverse(root, k);
        return kth;
    }
};
