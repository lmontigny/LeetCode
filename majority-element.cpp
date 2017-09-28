// LeetCode 169. Majority Element

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      unordered_map<int,int> m;
      for(int i=0; i<nums.size(); i++){
        m[nums[i]]++;
      }
      
        int majority;
        for(auto& p: m){
            if(p.second > nums.size()/2) {
                majority = p.first;
            }
        }

        return majority;
    }
};
