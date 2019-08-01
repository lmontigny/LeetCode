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
    void bfs(TreeNode* root, vector<vector<int>> &res, int depth){
        if(!root) return;
        std::queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int len = q.size();
            vector<int> cols;
            
            for(int i=0; i<len; i++){
                TreeNode* current = q.front();
                q.pop();
                cout << current->val << endl;
                cols.push_back(current->val);    
            
                if(current->left)
                    q.push(current->left);
                if(current->right)
                    q.push(current->right);
            }
            res.push_back(cols);
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        bfs(root, result, 0);
        return result;
    }
};

            // add for loop with the size of the queue
            // this loop is just for the vector part
            /*
            Example:
                3
               / \
              9  20
                /  \
               15   7
            */
            
