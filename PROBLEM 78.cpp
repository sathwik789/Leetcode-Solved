class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        int val = (1 << n);
        for(int num = 0;num < val;num++){
            vector<int>  List = {};
            for(int i =0;i<n;i++){
                if(num & (1<<i)){
                    List.push_back(nums[i]);
                }
            }
            ans.push_back(List);
        }
        return ans;
    }
};
