class Solution {
public:
    int minhours(vector<int> &piles,int speed){
        int sum =0;
        for(int i =0;i<piles.size();i++){
            sum  += (piles[i] + speed -1)/speed;
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = INT_MIN;
        for(int i =0;i<piles.size();i++){
            if(piles[i] > max){
                max = piles[i];
            }
        }
        int low = 1;
        int high = max;
        while(low<=high){
            int mid = (low+high)/2;
            int hours = minhours(piles,mid);
            if(hours <= h){
                high = mid-1;
            }
            else{
                low = mid +1;
            }
        }
        return low;
    }
};
