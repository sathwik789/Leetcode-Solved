class Solution {
    private:
    char binarysearch(vector<char>& letters, char tar){
        int start = 0, end = letters.size() -1;
        char ans = letters[0];
        while(start<= end){
            int mid = (start+end)/2;
            if(letters[mid] > tar){
                ans = letters[mid];
                end = mid -1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        return binarysearch(letters, target);
    }
};
