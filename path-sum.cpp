// 112. Path Sum
// The idea is to substract val to the sum, if the sum equals 0 then we found a valid path.


class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        sum -= root->val;
        if (!root->left && !root->right) return sum == 0;
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};
