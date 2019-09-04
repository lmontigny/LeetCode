class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()) return intervals;
        sort(intervals.begin(), intervals.end());

        int previous=0;
        for(int i=1; i<intervals.size(); i++){
             
            // Overlapping interval found
            if(intervals[i][0]<=intervals[previous][1]){
                // Current interval is bigger, keep this one
                if(intervals[i][1]>intervals[previous][1]){
                    intervals[previous][1] = intervals[i][1];
                }
                // Keep only previous
                intervals.erase(intervals.begin()+i); // Slow
                i = previous;
            }
            else{
                previous = i;
            }
        }
        return intervals;
    }
};
