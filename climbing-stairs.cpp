// 70. Climbing Stairs
// Stair 1=one way
// Stair 2=two way
// Stair 3=[Stair(n-2)+2 stair]+[Stair(n-1)+1 stair]

class Solution {
public:
    int climbStairs(int n) {
         vector<int> steps(n,0);
         steps[0]=1; //first step
         steps[1]=2;
         for(int i=2;i<n;i++)
         {
             steps[i]=steps[i-2]+steps[i-1];
         }
         return steps[n-1];
    }
};
