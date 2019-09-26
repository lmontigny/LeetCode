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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        
        traverseDFS(root, res, to_string(root->val));
        return res;
    }
private:
    vector<string> traverse(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        vector<string> res;
        //res.push_back(to_string(root->val));
        
        while(!q.empty()){          
            for(int i=0; i<q.size(); i++){
                TreeNode* head = q.front();
                q.pop();
                if(head->left) q.push(head->left);
                if(head->right) q.push(head->right);
                
                cout << head->val << endl;
            }
        }
        
        return res;
    }

    void traverseDFS(TreeNode* root, vector<string>& res, string t){
        if(!root->left && !root->right){
            res.push_back(t);
            return;
        }
        
        cout << root->val << endl;
        if(root->left) 
            traverseDFS(root->left, res, t + "->" + to_string(root->left->val));
        if(root->right) 
            traverseDFS(root->right, res, t + "->" + to_string(root->right->val));
    }
};
