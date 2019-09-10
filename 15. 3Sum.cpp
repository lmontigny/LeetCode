/*
The way to think about it is since it's 3 sum, there's only going to be 3 numbers. 
So to find the combinations of 3 numbers, he is iterating through the list with the 
first pointer, and then trying to find two extra numbers to sum to 0. Since the list 
is ordered, the right pointer will always be higher than the middle pointer. So if 
the sum is too large, you can move the right pointer back one. On the other hand, if 
the sum is too small (below 0), then move the middle pointer up one.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        
        sort(nums.begin(),nums.end());
        // Fix the 1st pointer
        for(int i=0; i<nums.size(); i++){
            // After the first iteration, if the next element is the same, we avoid it
            // otherwise we will get the same vector solution as the previous
            if(i>0 && nums[i]==nums[i-1])
                continue;
                
            // Init 2nd and 3rd pointer, most left and most right    
            int l=i+1;
            int r=nums.size()-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum>0) r--;
                else if(sum<0) l++;
                else{
                    res.push_back(vector<int> {nums[i],nums[l],nums[r]});
                    // Avoid same element, move pointer to the last identical element
                    while(l+1<r && nums[l]==nums[l+1]) l++;
                    while(r-1>l && nums[r]==nums[r-1]) r--;
                    // Move to the next non-identical element
                    l++; r--;
                }
            }           
        }
        
        return res;
    }
};
