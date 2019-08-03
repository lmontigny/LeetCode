class Solution {
public:
   
    int findMin(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int left = 0;
        int right = nums.size()-1;
        while(left < right){
            if(nums[left]<nums[right])
                return nums[left];
            
            int mid = left + (right-left)/2;
            cout << mid << endl;
            if(nums[mid] > nums[right])
                left = mid+1;
            else
                right = mid;
        }
        return nums[left];
    }
};
