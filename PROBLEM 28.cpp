class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        for(int i =0;i<n- m +1;i++){
            if(haystack.substr(i,needle.size()) == needle){
                return i;
                break;
            }
        }
        return -1;

    }
};
