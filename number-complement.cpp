//  476. Number Complement

class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while (num & mask) mask <<= 1;
        return ~mask & ~num;
    }
};


/*
Example with 5:
~0           = 11111111

while() // shift mask binary until the AND operation of binary is 0, only (1 & 1) =1 else =0)
num          = 00000101
mask         = 11111000

// return the sum of the complement of each number
~mask & ~num = 00000010
give 2
*/

/*
Example with 3:
~0           = 11111111

while() // shift mask binary until the sum of the binary is 0
num          = 00000011
mask         = 11111100

// return the sum of the complement of each number
~mask & ~num = 00000010
give 0
*/
