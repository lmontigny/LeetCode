// 258. Add Digits

class Solution {
public:
    int addDigits(int num) {
        int total = 0;
        if(num==0) return 0;
        if(num<10) return num;
        while(num>=10){
            int rest = num%10;
            num /= 10;
            total = rest + num; 
            num = total;
        }
      return total;      
    }
};
