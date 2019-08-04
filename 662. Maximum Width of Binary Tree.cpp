/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 
 Regardless whether these nodes exist:

    Always make the id of left child as parent_id * 2;
    Always make the id of right child as parent_id * 2 + 1;

So we can just:

    Record the id of left most node when first time at each level of the tree during an pre-order run.(you can tell by check the size of the container to hold the first nodes);
    At each node, compare the distance from it the left most node with the current max width;


 */
class Solution {
public:
    int width=0;
    vector<int> lefts;
    void traverse(TreeNode* root, unsigned int depth, unsigned int id){
        if(!root) return;
        
        // save heap id of the left-most node at each level
        // by looking at the size of the container
        if (depth == lefts.size()) 
            lefts.push_back(id);
        width=max(width,(int)(id+1 -lefts[depth]));
        //cout << root->val << " " << id << " " << lefts[depth] << endl;

        traverse(root->left, depth+1, id*2);
        traverse(root->right, depth+1, id*2+1);
    }
    
    
    int widthOfBinaryTree(TreeNode* root) {
        traverse(root, 0, 1);
        return width;
        
    }
};
