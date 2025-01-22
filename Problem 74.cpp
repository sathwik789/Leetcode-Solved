class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int r = 0,c = col -1;
        while(r < row && c >= 0){
            int cur = matrix[r][c];
            if(cur == target){
                return true;
            }
            if(target > matrix[r][c]){
                r++;
            }
            else{
                c--;
            }
        }
        return false;
    }
};
