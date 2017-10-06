// 167. Two Sum II - Input array is sorted

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap;
        for(int i=0; i<nums.size(); i++){
            int numberToFind  = target - nums[i];
            if(myMap.find(numberToFind ) != myMap.end() ){
                return vector<int>{myMap.find(numberToFind)->second, i+1};
            }
            myMap[nums[i]] = i+1;
        }
    }
};

