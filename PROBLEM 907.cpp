using ll = long long;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int sum  =0;
        int n = arr.size();
        vector<int> pse(n,-1);
        vector<int> nse(n,n);
        int mod = (int)(1e9 +7);
        stack<int> st;
        for(int i = 0;i<n;++i){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i] = st.top();
            }
            st.push(i);
        }
        st = stack<int>();
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i]  = st.top();
            }
            st.push(i);
        }
        for(int i = 0;i<arr.size();i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            sum += static_cast<ll>(left) * (right) *arr[i]%mod;
            sum %= mod;
        }
        return sum;
    }
};
