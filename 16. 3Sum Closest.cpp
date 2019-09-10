class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        int result = nums[0] + nums[1] + nums[nums.size() - 1];
        sort(nums.begin(),nums.end());
        
        for(int i=0; i<nums.size()-2; i++){
            // Avoid repetition of computation
            if(i > 0 && nums[i] == nums[i-1]) 
                continue;
            
            int l=i+1;
            int r=nums.size()-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                // "Delta" = difference wit the target
                // Check if the delta is smaller than the initial delta
                if(abs(sum-target)<abs(result-target))
                    result=sum;
                
                if(sum>target) 
                    r--;
                else if(sum<target) 
                    l++;
                else{
                    return target;
                }
            }           
        }
        return result;
    }
};
