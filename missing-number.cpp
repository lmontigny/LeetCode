// 268. Missing Number
// sum(1,n)_i=n*(n+1)/2
// The difference with the sum of the vector is the missing number.


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long n = nums.size();
        return n * (n+1) / 2 - accumulate(begin(nums), end(nums), 0);
    }
};

