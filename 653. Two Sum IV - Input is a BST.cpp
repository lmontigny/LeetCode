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
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root, nums); //use the fact that it is a BST
        return findSum(nums, k);
    }
private:   
    void inorder(TreeNode* root, vector<int>& nums){
        if(!root) return;
        
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    
    bool findSum(vector<int>& nums, int target){
        int i = 0;
        int j = nums.size()-1;
        
        while(i<j){
            int sum = nums[i]+nums[j];
            if(sum == target) return true;
            else if(sum<target) i++;
            else j--;
        }
        return false;
    }
};

