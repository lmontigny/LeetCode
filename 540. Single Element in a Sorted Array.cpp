// Complexity O(n)
// to be improved with binary search O(log n)

class Solution {
public:   
    int counting(vector<int>& arr){
        if(arr.size()==1) return arr[0];
        if(arr.empty()) return 0;
        
        // Find max value
        int n = arr.size();
        int range = *std::max_element(arr.begin(), arr.end());
        int count[range+1] = {0};
        
        // Count nb occurence
        for(int i=0; i<n; i++){
            ++count[arr[i]];
        }

        // Find single occurence
        for(int i=0; i<range+1; i++){
                if(count[i]==1){
                        return i;
                }
        }
        
        return 0;
    }

    int singleNonDuplicate(vector<int>& nums) {
        return counting(nums);
    }
};
