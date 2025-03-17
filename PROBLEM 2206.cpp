class Solution {
public:
    bool divideArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int pairs = nums.size()/2;
        int cnt = 0;
        for(int i = 0;i<nums.size();i+=2){
            if(nums[i] == nums[i+1]) cnt++;
        }
        if(cnt == pairs){
            return true;
        }
        return false;
    }
};
