// Solution to Single Number problem from LeetCode in C++
// Use XOR 
/*
A   B   Output
0	0	0
0	1	1
1	0	1
1	1	0
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i=1; i<nums.size(); i++){
            nums[0] ^= nums[i];            
        }
        return nums[0];
    }
};


     
