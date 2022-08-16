class Solution {
public:
    
    int count(string s,int l,int r){
        if(l>=0 and r<s.size() and s[l]==s[r]){
            return 1+count(s,l-1,r+1);
        }
        return 0;
    }
    
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            int l = count(s,i,i);// odd size
            int r = count(s,i,i+1);// even size
            cnt += (l+r);
        }
        return cnt;
    }
};