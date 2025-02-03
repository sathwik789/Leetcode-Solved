class Solution {
public:
    int maxDepth(string s) {
        int cnt =0;
        int max = INT_MIN;
        for(auto c :s){
            if(c == '('){
                cnt++;
            }
            if(c == ')'){
                cnt--;
            }
            if(cnt > max){
                max = cnt;
            }
        }
        return max;
    }
};
