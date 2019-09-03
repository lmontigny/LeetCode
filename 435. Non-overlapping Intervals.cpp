/*
x1-----y1 (i-1)
    x2-----y2 (i)
non overlap if x2>y1

    x1-----y1
x2------y2
non overlap if x1>y2
*/

/*
Sort all intervals by starting time O(nlog n)
starting time of interval[i+1] must be greater than or equal to interval[i]. 

one for loop O(n) over the intervals
check if overlapping, keep the smallest intervals
otherwise take the current as reference
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        if(intervals.empty()) return count;
        sort(intervals.begin(), intervals.end());
        
        int pre = 0;
        for(int i=1;i<intervals.size(); i++){
            if(intervals[pre][1] > intervals[i][0]){
                count++;
                if(intervals[pre][1] > intervals[i][1]) pre=i;
            }
            else 
                pre=i;
        }
        
        return count;
    }
};
