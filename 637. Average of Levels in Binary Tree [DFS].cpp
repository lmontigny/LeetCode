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
    vector<int> n;
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        traverse(root, res, 0);
        
        for(int i=0; i<res.size(); i++){
            res[i] /= n[i];
        }
        return res;
        
    }
private:
    void traverse(TreeNode* root, vector<double>& res, int level){
        if(!root) return;
        
        cout << root->val << " " << level << endl;
        if(res.size()==level){
            res.push_back(root->val);
            n.push_back(1);
        }
        else{
            res[level] += root->val;
            n[level]++;
        }
        
        level++;
        
        traverse(root->left, res, level);
        traverse(root->right, res, level);
    }
};
