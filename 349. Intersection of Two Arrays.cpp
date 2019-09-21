class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> htable;
        vector<int> res;
        
        for(int i=0; i<nums1.size(); i++){
            htable.insert(nums1[i]);
        }
        
        for(int i=0; i<nums2.size(); i++){
            if (htable.find(nums2[i]) != htable.end()){ 
                res.push_back(nums2[i]);
                htable.erase(htable.find(nums2[i]));
            }
        }
        
        return res;
    }
};
