class Solution {
public:
    int countPrimes(int n){
        int cnt = 0;
        vector<bool> arr(n+1,true);
        arr[0] = arr[1]  = false;
        for(int i =2 ;i*i<=n;i++){
            if(arr[i]){
                for(int j = i*i ;j<=n;j+=i){
                    arr[j] = false;
                }
            }
        }
        for(int i = 2;i<n;i++){
            if(arr[i]){
                cnt++;
            }
        }
        return cnt;
    }
};
