class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256,-1);
        if(s.size() == 0){
            return 0;
        }
        int l =0, r =0;
        int n = s.size();
        int len = INT_MIN;
        while(r < n){
            if(mpp[s[r]] != -1){
                l = max(mpp[s[r]]+1,l);
            }
            mpp[s[r]] = r;
            len = max(r-l+1,len);
            r++;
        }
        return len;
    }
};
