class Solution {
public:
    int postoship(vector<int>& weights,int mid){
        int n = weights.size();
        int cap = 0;
        int d =1;
        for(int i =0;i<n;i++){
            cap += weights[i];
            if(cap > mid){
                d++;
                cap = weights[i];
            }
        }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int total = 0;
        int max = INT_MIN;
        for(int i =0;i<n;i++){
            total = total + weights[i];
            if(weights[i] > max){
                max = weights[i];
            }
        }
        int l =max, r = total;
        while(l<=r){
            int mid = l+(r-l)/2;
            int da = postoship(weights, mid);
            if(da <= days){
                r = mid -1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};
