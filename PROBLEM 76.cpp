class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty() ||s.length() < t.length())  return "";
        int hash[256] = {0};
        int n = s.length();
        int m = t.length();
        int maxlen = INT_MAX;
        int sIndex = -1;
        int l =0;
        int r =0;
        int cnt =0;
        for(int i =0;i<t.size();i++){
            hash[t[i]]++;       
        }
        while(r < n){
            if(hash[s[r]] > 0) cnt = cnt+ 1;
            hash[s[r]]--;
            r++;
            while(cnt == m){
                if((r-l+1) < maxlen){
                    maxlen = (r-l+1);
                    sIndex =l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt = cnt -1;
                l++;
            }

        }
        return (sIndex == -1)? "" : s.substr(sIndex,maxlen -1);
    }
};
