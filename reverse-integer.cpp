class Solution {
public:
    int reverse(int x) {
        long long res{0};
        while(x){
            int last = x%10;
            x /= 10;
            res = res*10 + last;
        }
        if (res > INT_MAX || res < INT_MIN) res = 0;

        return res;
    }
};
