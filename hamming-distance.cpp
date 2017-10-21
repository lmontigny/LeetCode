// 461. Hamming Distance


class Solution {
public:
    int hammingDistance(int x, int y) {
        x^=y;
        cout << x << endl;
        int count=0;
        while(x!=0){
          x = x&(x-1);
          count++;
        }
        return count;        
    }
};
