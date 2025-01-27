class Solution {
public:
    int floor(vector<int> &nums, int target){
        int low = 0;
        int high = nums.size() -1;
        int floor = -1;
        while(low <= high){
            int mid = (low +high)/2;
            if(nums[mid] == target){
                floor = mid;
                high = mid -1;
            }
            else if(nums[mid] < target){
                low = mid +1;
            }
            else{
                high = mid -1;
            }
        }
        return floor;
    }
    int ceil(vector<int> &nums, int tar){
        int low =0;
        int high = nums.size() -1;
        int ceil = -1;
        while(low<=high){
            int mid = low +(high - low)/2;
            if(nums[mid] == tar){
                ceil = mid;
                low = mid +1;
            }
            else if(nums[mid] < tar){
                low=mid +1;
            }
            else{
                high = mid -1;
            }
        }
        return ceil;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int f = floor(nums, target);
        int c = ceil(nums, target);
        return {f,c};
    }
};
