class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int cnt1 =0;
        int cnt2 =0;
        int el1 ,el2;
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(cnt1 == 0 && nums[i] != el2){
                cnt1 =1;
                el1 = nums[i];
            }
            else if(cnt2 ==0 && nums[i] != el1){
                cnt2 =1;
                el2 = nums[i];
            }
            else if(nums[i] ==  el1){
                cnt1++;
            }
            else if(nums[i] == el2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        int cnt =0;
        int ct =0;
        for(int i = 0;i<n;i++){
            if(nums[i] == el1){
                cnt++;
            }
            else if(nums[i] == el2){
                ct++;
            }
        }
        int a = int(n/3) +1;
        if(cnt >= a){
            ans.push_back(el1);
        }
        if(ct >= a ){
            ans.push_back(el2);
        }
        return ans;
    }
};
