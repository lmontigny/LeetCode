int binarySearch(int* nums, int low, int high, int target) {
    if(high>=low){
        int mid = low+(high-low)/2;
        if(nums[mid]==target)
            return mid;

        if(target<nums[mid])
            return binarySearch(nums, low, mid-1, target);

        return binarySearch(nums, mid+1, high, target);
    }
    return -1;
}

int search(int* nums, int numsSize, int target) {
    return binarySearch(nums, 0, numsSize-1, target);
}
