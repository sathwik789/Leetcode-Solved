class Solution {
public:
    vector<int> ncr(int n){
        int res = 1;
        vector<int> a;
        a.push_back(res);
        for(int i =1;i<n;i++){
            res = res * (n-i);
            res = res/i;
            a.push_back(res);
        }
        return a;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        //FOR FINDING ANY ROW AND COL VALUE OF PASCAL TRAINGLE use n!/r! * (n-r)!
        //TO PRING Nth row of Pascal Traingle
        //THIRD TO PRINT COMPLETE PASCAL TRAINGLE
        for(int i =1;i<=numRows;i++){
            ans.push_back(ncr(i));
        }
        return ans;
    }
};
