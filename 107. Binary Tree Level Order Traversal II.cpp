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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        helper(root,res,0);
        
        reverse(res.begin(),res.end());
        return res;
    }
private:
    void helper(TreeNode* root, vector<vector<int>> &res, int level){
        if(!root) return;
        
        if(res.size()==level)
            res.push_back(vector<int>());
        
        helper(root->left, res, level+1);
        helper(root->right, res, level+1);
        
        res[level].push_back(root->val);
    }
