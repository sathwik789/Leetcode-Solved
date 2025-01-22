class Solution {
public:
    int uniquePaths(int m, int n) {
        int arr[m][n];
        for(int i =m-1;i>=0;i--){
            arr[i][n-1] = 1;
        }
        for(int j = n-1;j>=0;j--){
                arr[m-1][j] = 1;
        }
        for(int row = m-2;row>=0;row--){
            for(int col = n-2;col >=0;col--){
                arr[row][col] = arr[row+1][col] + arr[row][col+1];
            }
        }
        return arr[0][0];
    }
};
