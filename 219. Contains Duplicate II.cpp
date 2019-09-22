class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for(int i = 0; i < nums.size(); ++i) {
            // Sliding windows, save in the hashamp only the last known position! 
            // Check if key exist and return true with the first difference smaller than k
            if(hashMap.find(nums[i]) != hashMap.end() && i - hashMap[nums[i]] <= k)  
                return true;
            hashMap[nums[i]] = i;
        }
        return false;
    }
};
