/*
Sort and two pointers Solution:
Time: O(max(m, n) log(max(m, n))) Space: O(m + n)
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        int ptr1 = 0;
        int ptr2 = 0;
        
        vector<int> res;
        
        while(ptr1<nums1.size() && ptr2<nums2.size()){
            if(nums1[ptr1]==nums2[ptr2]){
                res.push_back(nums1[ptr1]);
                ptr1++;
                ptr2++;
            }
            else if(nums1[ptr1]<nums2[ptr2]){
                while((ptr1+1)<nums1.size() && nums1[ptr1]==nums1[ptr1+1]) ptr1++;
                ptr1++;
            }
            else if(nums1[ptr1]>nums2[ptr2]){
                while((ptr2+1)<nums2.size() && nums2[ptr2]==nums2[ptr2+1]) ptr2++;
                ptr2++;
            }
        }
        
        return res;   
    }
};


/*
Hash table solution:
Time: O(m + n) Space: O(m + n)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for(int i = 0; i < (int)nums1.size(); i++) dict[nums1[i]]++;
        for(int i = 0; i < (int)nums2.size(); i++)
            if(--dict[nums2[i]] >= 0) res.push_back(nums2[i]);
        return res;
    }
};
*/
