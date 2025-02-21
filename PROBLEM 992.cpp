class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (length(nums,k) - length(nums,k-1));
    }
private:
    int length(vector<int>& nums, int k){
        int left =0;
        int n= nums.size();
        int total =0;
        unordered_map<int,int> mp;
        for(int r = 0;r<n;r++){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            total += (r - left +1);
        }
        return total;
    }
    
};
