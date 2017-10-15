// 9. Palindrome Number
// Palindrome: if(3443 == reverse(3443)) true

class Solution {
public:
    bool isPalindrome(int x) {
         if(x<0) return false;
         int n = x;
         int rev = 0;
         while (x > 0)
         {
              int dig = x % 10;
              rev = rev * 10 + dig;
              x = x / 10;
         }
        return n==rev;
    }
};
