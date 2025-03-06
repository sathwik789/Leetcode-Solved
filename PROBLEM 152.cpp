class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprd = INT_MIN;
        int n = nums.size();
        int prod = 1, suff = 1;
        for(int i =0;i<nums.size();i++){
            if(prod == 0) prod = 1;
            if(suff == 0) suff = 1;
            prod *= nums[i];
            suff *= nums[n - i -1];
            maxprd = max(maxprd , max(prod,suff));
        }
        return maxprd;
    }
};
