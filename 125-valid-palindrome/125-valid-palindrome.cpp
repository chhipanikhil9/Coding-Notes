class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i=0,j = n-1;
        while(i<j){
            while(!isalnum(s[i]) and i<j){
                i++;
            }
            while(!isalnum(s[j]) and i<j){
                j--;
            }
            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
            i++,j--;
        }
        return true;
    }
};