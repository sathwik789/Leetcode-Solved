class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return (sumMaxs(nums) - sumMins(nums));
    }
private:
    long long sumMins(vector<int>& nums){
        long long total = 0;
        int n = nums.size();
        vector<int> nse(n,n);
        vector<int> pse(n,-1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        st = stack<int> ();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
            int left = i - pse[i];  // Distance from PSE
            int right = nse[i] - i; // Distance to NSE
            total += 1LL * left * right * nums[i];
        }
        return total;
    }
    long long sumMaxs(vector<int>& nums){
        long long total = 0;
        int n = nums.size();
        vector<int> nge(n,n), pge(n, -1);
        stack<int> st;
        for(int i =n-1;i>= 0;i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            nge[i]  = st.empty()? n : st.top();
            st.push(i);
        }
        st= stack<int>();
        for(int i =0;i<n;i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
            int left = i - pge[i];
            int right = nge[i]  - i;
            total += left * right * 1ll*nums[i];
        }
        return total;
    }
};
