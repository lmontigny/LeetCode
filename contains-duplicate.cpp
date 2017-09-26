// Solution to the contains duplicate problem from LeetCode in C++

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        bool is_unique = std::unique(nums.begin(), nums.end()) == nums.end(); 
        return !is_unique;
    }
};


/*
    // Or this version
    for (int i = 0; i < nums.length - 1; ++i) {
        if (nums[i] == nums[i + 1]) return true;
    }
    return false;
*/
