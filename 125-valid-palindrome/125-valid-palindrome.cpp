class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        int n = s.size();
        for(int i=0;i<n;i++){
            if((('a'<=s[i] and s[i]<='z') or ('A'<=s[i] and s[i]<='Z')) or ('0'<=s[i] and s[i]<='9')){
                temp += tolower(s[i]);
            }
        }
        cout<<temp;
        int i=0,j = temp.size()-1;
        while(i<j){
            if(temp[i]!=temp[j]){
                return false;
            }
            i++,j--;
        }
        return true;
    }
};