class Solution {
public:
    int posi(vector<int> &bloomDay, int day, int m, int k){
        int cnt =0;
        int r =0;
        for(int i =0;i<bloomDay.size();i++){
            if(bloomDay[i] <= day){
                cnt++;
            }
            else{
                r += (cnt/k);
                cnt = 0;
            }
        }
        r += (cnt/k);
        return r>=m;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int max = INT_MIN;
        int n = bloomDay.size();
        long long val = m * 1LL *k * 1LL;
        if(val > n) return -1;
        for(int i =0;i<n;i++){
            if(bloomDay[i] > max){
                max  = bloomDay[i];
            }
        }
        int low = 0;
        int high = max;
        while(low<= high){
            int mid = (low+high)/2;
            if(posi(bloomDay,mid,m,k)){
                high = mid -1;
            }
            else{
                low = mid +1;
            }
        }
        return low;
        
    }
};
