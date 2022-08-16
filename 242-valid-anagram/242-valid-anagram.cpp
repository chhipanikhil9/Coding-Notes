class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        // int mpt[30] = {0};
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            mp[t[i]]--;
        }
        int f = 0;
        for(auto x:mp){
            if(x.second != 0){
                f = 1;
                break;
            }
        }
        if(f) return false;
        return true;
    }
};