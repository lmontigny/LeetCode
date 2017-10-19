// 633. Sum of Square Numbers
// The idea is to check is the difference c-a^2 = b^2 is a perfect square, if yes return true.

class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==0) return true;
        for(int i=0; i<sqrt(c); i++){
            int diff = c-pow(i,2);
            if(sqrt(diff)==floor(sqrt(diff))) return true;
        }
        return false; 
    }
};
