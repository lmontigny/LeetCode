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
    int findMax(const vector<int>&nums, int* pos){
        int max_val = nums[0];
        *pos = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>max_val) {
                max_val = nums[i];
                *pos = i;
            }
        }
        return max_val;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty()) return NULL;
        
        int pos = 0;
        int max_val = findMax(nums, &pos);        
        TreeNode* res = new TreeNode(max_val);
        
        vector<int> left_array(nums.begin(), nums.begin()+pos);
        vector<int> right_array(nums.begin()+pos+1, nums.end());

        res->left = constructMaximumBinaryTree(left_array);
        res->right = constructMaximumBinaryTree(right_array);
        
        return res;
    }
};
