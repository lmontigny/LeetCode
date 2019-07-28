class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        if(nums.empty()) return res;
        
        int max = *max_element(nums.begin(), nums.end()); 
        int min = *min_element(nums.begin(), nums.end()); 
        int range = max - min + 1;
        vector<int> twice(range);

        for(int i=0; i<nums.size(); i++){
            if(++twice[nums[i]-min]>1) res.push_back(nums[i]);
        }
        
        return res;
    }
};
