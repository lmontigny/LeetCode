//============================================================================
// Name        : Fractal.cpp
// Author      : lmontigny
// Version     :
// Copyright   : 
// Description : Solution in C++ to the Two Sum problem from Leetcode
//============================================================================

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                if (i==j) continue;
                else if( (nums[i]+nums[j]) == target){
                    v.push_back(i);
                    v.push_back(j);
                    return v;
                }
            }
        }
        return vector<int>{0};
    }

    vector<int> twoSumMap(vector<int>& nums, int target){
        unordered_map<int, int> myMap;
        for(int i=0; i<nums.size(); i++){
            int numberToFind  = target - nums[i];
            if(myMap.find(numberToFind ) != myMap.end() ){
                return vector<int>{myMap.find(numberToFind)->second, i};
            }
            myMap[nums[i]] = i;
        }
    }
};


int main() {

    vector<int> nums{12,23,2,7,11,15};
    int target{9};

    //Solution loop;
    //vector<int> res = loop.twoSum(nums, target);

    Solution *loop1 = new Solution;

    vector<int> res1 = loop1->twoSum(nums, target);
    for(auto i: res1){
        cout << i << endl;
    }

    vector<int> res2 = loop1->twoSumMap(nums, target);
    for(auto i: res2){
        cout << i << endl;
    }


    delete loop1;
	return 0;
}
