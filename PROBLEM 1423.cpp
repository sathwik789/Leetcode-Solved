class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftsum = 0;
        int rightsum =0;
        for(int i =0;i<k;i++){
            leftsum += cardPoints[i];
        }
        int maxsum = leftsum;
        int rind  = n-1;
        for(int i = k-1;i>=0;i--){
            leftsum -= cardPoints[i];
            rightsum += cardPoints[rind];
            rind--;
            maxsum  = max(maxsum,(leftsum + rightsum));
        }
        return maxsum;
    }
};
