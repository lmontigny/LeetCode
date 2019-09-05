class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) return 0;
        int arrows=points.size();
        sort(points.begin(), points.end());
        
        int pre = 0;
        for(int i=1;i<points.size(); i++){
            // Intersection found
            if(points[pre][1] >= points[i][0]){
                arrows--;
                // Keep smallest interval
                if(points[pre][1] > points[i][1]) pre=i;
            }
            else 
                pre=i;
        }
        return arrows;
    }
};
