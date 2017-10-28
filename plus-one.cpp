// 66. Plus One

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool carry = true;
        
        for(int i=digits.size()-1; i >= 0 && carry; i--) {   //keep going if carry is true
            carry = (++digits[i]%=10) == 0;                  // 9->0
        }

        if(carry) {
            digits.insert(digits.begin(), 1);
        }
    
        return digits;
    }
};
