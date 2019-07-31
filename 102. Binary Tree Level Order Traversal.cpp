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
    // add depth as parameter
    void traverse(TreeNode* root, vector<vector<int>> &res, int depth){
        if(!root) return;

        // Create empty vector
        // first element, size 0, create vec res.size is now 1
        // root->left, 1==1, create vec, res.size is now 2, right->right won't go in
        if(res.size() == depth){
            //cout << res.size() << " " << root->val << endl;
            res.push_back(vector<int>());
        }
            
        // Push elements along the 'depth' row
        res[depth].push_back(root->val); 

        // Inorder traversal
        traverse(root->left, res, depth+1);
        traverse(root->right, res, depth+1);
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        traverse(root, result, 0);
        return result;
    }
};
