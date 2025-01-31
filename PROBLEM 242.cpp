class Solution {
public:
    bool isAnagram(string s, string t) {
        // map<char,int> mp1;
        // map<char,int> mp2;
        if(s.length() != t.length()){
            return false;
        }   
        // for(int i =0;i<s.length();i++){
        //     mp1[s[i]]++;
        //     mp2[t[i]]++;
        // }
        // for(int i=0;i<s.length();i++){
        //     char ch = s[i];
        //     if(mp1[ch] != mp2[ch]){
        //         return false;
        //     }
        // }
        // return true;
        vector<int> freq(26,0);
        for(auto it: s){
            freq[it - 'a']++;
        }
        for(auto it:t){
            freq[it - 'a']--;
        }
        for(int i =0;i<freq.size();i++){
            if(freq[i] != 0){
                return false;
            }
        }
        return true;
    }
};
